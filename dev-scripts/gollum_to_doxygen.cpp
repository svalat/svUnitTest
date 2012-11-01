/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************* HEADER *********************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

/********************* USING **********************/
using namespace std;

/********************* CONSTS *********************/
const int BUFFER_SIZE = 2048;
const char MANGLE_BLACKLIST[] = " \\/;:.!()[]{}@,'\"\n";

/********************* ENUM ***********************/
enum Mode
{
	MODE_START,
	MODE_STD,
	MODE_PAGE,
	MODE_SECTION,
	MODE_SUBSECTION,
	MODE_LIST,
	MODE_SUBLIST,
	MODE_LINK,
	MODE_INTLINK_1,
	MODE_INTLINK_2,
	MODE_INTLINK_3,
	MODE_INTLINK_4,
	MODE_TABLE,
	MODE_CODE,
	MODE_VERBATIM,
	MODE_ITALIC,
	MODE_BOLD,
	MODE_INLINE_VERBATIM,
};

/******************* FUNCTION ********************/
inline int mode_is_section(enum Mode mode)
{
	return (mode == MODE_PAGE || mode == MODE_SECTION || mode == MODE_SUBSECTION);
}

/******************* FUNCTION ********************/
int is_valid_char_for_mangle(char value)
{
	int i = 0;
	while ( MANGLE_BLACKLIST[i] != '\0')
	{
		if (MANGLE_BLACKLIST[i] == value)
			return 0;
		++i;
	}
	return 1;
}

/******************* FUNCTION ********************/
void print_mangled_name(const char * pre,char * buffer,const char * post)
{
	int i = 0;
	printf("%s",pre);
	while (buffer[i] != '\0')
	{
		if (is_valid_char_for_mangle(buffer[i]))
			putchar(buffer[i]);
		else if (buffer[i]=='/')
			cout << "slash";
		++i;
	}
	printf("%s",post);
}

/******************* FUNCTION ********************/
void print_list(enum Mode mode,bool numlist)
{
	switch(mode)
	{
		case MODE_LIST:
			if (numlist)
				printf(" -# ");
			else
				printf(" - ");
			break;
		case MODE_SUBLIST:
			if (numlist)
				printf("     -# ");
			else
				printf("     - ");
			break;
		default:
			fprintf(stderr,"Unknown mode : %d\n",mode);
			abort();
	}
}

/******************* FUNCTION ********************/
char * cut_ext(char * buffer)
{
	int i = 0;
	while (buffer[i] != '\0' && buffer[i] != '.')
		++i;
	if (buffer[i] == '.')
		buffer[i] = '\0';
	return buffer;
}

/******************* FUNCTION ********************/
string get_basename_noext(const char * filename)
{
	char buf[BUFFER_SIZE];
	strncpy(buf,filename,BUFFER_SIZE);
	string res = cut_ext(basename(buf));
	return res;
}

/******************* FUNCTION ********************/
void print_section(enum Mode mode, char * buffer,const char * filename)
{
	string name = get_basename_noext(filename);
	//print header
	switch(mode)
	{
		case MODE_PAGE:			
			if (name == "Home")
				printf("@mainpage ");
			else
				cout << "@page " << name << " ";
			break;
		case MODE_SECTION:
			print_mangled_name("@section ",buffer," ");
			break;
		case MODE_SUBSECTION:
			print_mangled_name("@subsection ",buffer," ");
			break;
		default:
			fprintf(stderr,"Unknown mode : %d\n",mode);
			abort();
	}
}

/******************* FUNCTION ********************/
vector<string> split_string_on_char(char * buffer,char token)
{
	int i = 0;
	vector<string> res;
	string current;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == token)
		{
			res.push_back(current);
			current.clear();
		} else {
			current += buffer[i];
		}
		++i;
	}
	res.push_back(current);
	return res;
}

/******************* FUNCTION ********************/
bool string_end_by(string fullString,string ending)
{
	if (fullString.length() > ending.length()) {
		return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
	} else {
		return false;
	}
}

/******************* FUNCTION ********************/
bool is_image(string value)
{
	if (string_end_by(value,".png"))
		return true;
	else
		return false;
}

/******************* FUNCTION ********************/
bool is_http(const char * value)
{
	if (strncmp(value,"http://",7)==0)
		return true;
	else if (strncmp(value,"https://",8)==0)
		return true;
	else
		return false;
}

/******************* FUNCTION ********************/
bool fexists(const char *filename)
{
  ifstream ifile(filename);
  return ifile;
}

/******************* FUNCTION ********************/
void print_image(vector<string> & elem)
{
	string dotname = get_basename_noext(elem[0].c_str());
	dotname = "images/" + dotname + ".dot";
	if (fexists(dotname.c_str()) && string_end_by(elem[0].c_str(),".png"))
	{
		cout << "@dotfile " << dotname;
	} else {
		string indic = elem[1];
		string fname = get_basename_noext(elem[0].c_str());
		fname += ".png";
		if (indic == "frame")
			indic.clear();
		if (!indic.empty())
		{
			indic = " " + indic;
			cout << "\\htmlonly" << endl;
			cout << "<img src='" << fname << "'" << indic << "/>" << endl;
			cout << "\\endhtmlonly" << endl;
		} else {
			cout << "@image html " << fname << endl;
		}
		//cout << "@image latex " << elem[0].c_str() << endl;
		//cerr << "Images not supported for now." << endl;
		//abort();
	}
}

/******************* FUNCTION ********************/
void print_internal_link(char * buffer)
{
	vector<string> elem = split_string_on_char(buffer,'|');
	if (is_image(elem[0]))
		print_image(elem);
	else if (is_http(elem[1].c_str()))
		cout << "<a href='" << elem[1] << "' target='_blank'>" << elem[0] << "</a>";
	else if (elem.size() == 2)
		cout << "@subpage " << elem[1];
	else
		cout << "@subpage " << elem[0];
}

/******************* FUNCTION ********************/
bool is_code(const char * buffer)
{
	if (strncmp(buffer,"cpp\n",4)==0)
		return true;
	else if (strncmp(buffer,"c++\n",4)==0)
		return true;
	else if (strncmp(buffer,"make\n",5) == 0 || strncmp(buffer,"makefile\n",9) == 0)
		return true;
	else if (strncmp(buffer,"cmake\n",6) == 0)
		return true;
	else if (strncmp(buffer,"sh\n",3) == 0)
		return true;
	else if (strncmp(buffer,"xml\n",3) == 0)
		return true;
	else 
		return false;
}

/******************* FUNCTION ********************/
int convert_file(FILE * fp, const char * filename)
{
	char buffer[BUFFER_SIZE];
	char extractor[BUFFER_SIZE];
	char * buf;
	int i,j;
	int lastListLevel = 0;
	bool multilineMode = false;
	bool numlist = false;
	enum Mode mode = MODE_START;
	//check error
	if (fp == NULL)
		return EXIT_FAILURE;
	
	cout << "/**" << endl;

	while (!feof(fp))
	{
		buf = fgets (buffer, BUFFER_SIZE, fp);
		i = 0;
		if (multilineMode == false)
			mode = MODE_START;
		if (buf != NULL)
		while( buffer[i] != 0 )
		{
			/////////////////// ESCAPE CHAR /////////////////////
			if ((mode == MODE_STD || mode == MODE_START) && buffer[i] == '\\') {
				++i;
				putchar(buffer[i]);
			} else if ((mode == MODE_STD || mode == MODE_START) && strncmp(buffer+i,"\\\\",2)==0) {
				putchar('\\');
				++i;
			/////////////////// PAGE/SECTIONS ///////////////////
			} else if (mode == MODE_START && buffer[i]=='#') {
				mode = MODE_PAGE;
			} else if (mode == MODE_PAGE && buffer[i]=='#') {
				mode = MODE_SECTION;
			} else if (mode == MODE_SECTION && buffer[i]=='#') {
				mode = MODE_SUBSECTION;
			} else if (buffer[i] == ' ' && mode_is_section(mode)) {
			} else if (buffer[i] != ' ' && mode_is_section(mode)) {
				print_section(mode,buffer+i,filename);
				--i;
				mode = MODE_STD;
			///////////////////// BOLD /////////////////////////
			} else if ((mode == MODE_START || mode == MODE_STD) && strncmp(buffer+i,"**",2) == 0) {
				mode = MODE_BOLD;
				cout << "<b>";
				++i;
			} else if (mode == MODE_BOLD && strncmp(buffer+i,"**",2) == 0) {
				mode = MODE_STD;
				cout << "</b>";
				++i;
			} else if (mode == MODE_BOLD) {
				putchar(buffer[i]);
			/////////////////// LISTS //////////////////////////
			} else if (mode == MODE_START && buffer[i] == '*') {
				if (i <= lastListLevel)
				{
					mode = MODE_LIST;
					lastListLevel = i;
				} else {
					mode = MODE_SUBLIST;
				}
			} else if (mode == MODE_START && strncmp(buffer+i,"1.",2) == 0) {
				if (i <= lastListLevel)
				{
					mode = MODE_LIST;
					lastListLevel = i;
				} else {
					mode = MODE_SUBLIST;
				}
				numlist = true;
				++i;
			} else if ((mode == MODE_SUBLIST || mode == MODE_LIST) && buffer[i] == ' ') {
			} else if ((mode == MODE_SUBLIST || mode == MODE_LIST) && buffer[i] != ' ') {
				print_list(mode,numlist);
				--i;
				mode = MODE_STD;
			////////////////// EMPTY LINE //////////////////////
			} else if (mode == MODE_START && buffer[i] == '\n') {
				lastListLevel = 10000;
				puts("");
				numlist = false;
			/////////////// SKIP STARTING BLANK CHAR ///////////
			} else if (mode == MODE_START && buffer[i] != ' ' && buffer[i] != '\t') {
				--i;
				mode = MODE_STD;
			} else if (mode == MODE_START && (buffer[i] == ' ' || buffer[i] == '\t')) {
			/////////////////// EXTERNAL LINKS /////////////////
			} else if (mode == MODE_STD && strncmp(buffer+i,"<http://",8)==0) {
				mode = MODE_LINK;
			} else if (mode == MODE_LINK && buffer[i] == '>') {
				mode = MODE_STD;
			} else if (mode == MODE_LINK && buffer[i] != '>') {
				putchar(buffer[i]);
			////////////////////// LINKS ///////////////////////
			} else if ((mode == MODE_STD || mode == MODE_START) && buffer[i]=='[') {
				mode = MODE_INTLINK_1;
			} else if (mode == MODE_INTLINK_1 && buffer[i] == '[') {
				mode = MODE_INTLINK_2;
				j = 0;
			} else if (mode == MODE_INTLINK_2 && buffer[i] == ']') {
				mode = MODE_INTLINK_3;
			} else if (mode == MODE_INTLINK_3 && buffer[i] == ']') {
				extractor[j++] = '\0';
				print_internal_link(extractor);
				mode = MODE_STD;
			} else if (mode == MODE_INTLINK_2) {
				extractor[j++] = buffer[i];
			////////////////////// TABLE ///////////////////////
			} else if ((mode == MODE_STD || mode == MODE_START) && strncmp(buffer+i,"<table>",7)==0) {
				mode = MODE_TABLE;
				multilineMode = true;
				--i;
			} else if (mode == MODE_TABLE && strncmp(buffer+i,"</table>",8)==0) {
				mode = MODE_STD;
				multilineMode = false;
				--i;
			} else if (mode == MODE_TABLE) {
				putchar(buffer[i]);
			////////////////////// CODE ////////////////////////
			} else if ((mode == MODE_STD || mode == MODE_START) && strncmp(buffer+i,"```",3) == 0) {
				if (is_code(buffer+i+3))
				{
					mode = MODE_CODE;
					cout << "@code" << endl;
				} else {
					mode = MODE_VERBATIM;
					cout << "@verbatim" << endl;
				}
				multilineMode = true;
				break;
			} else if (mode == MODE_CODE && strncmp(buffer+i,"```",3) == 0) {
				mode = MODE_STD;
				cout << "@endcode" << endl;
				multilineMode = false;
				break;
			} else if (mode == MODE_VERBATIM && strncmp(buffer+i,"```",3) == 0) {
				mode = MODE_STD;
				multilineMode = false;
				cout << "@endverbatim" << endl;
				break;
			} else if ((mode == MODE_CODE || mode == MODE_VERBATIM) && strncmp(buffer+i,"```",3) != 0) {
				putchar(buffer[i]);
			////////////////////// ITALIC //////////////////////
			} else if (mode == MODE_STD && (buffer[i] == '*' || strncmp(buffer+i,"__",2) == 0 )) {
				mode = MODE_ITALIC;
				if (buffer[i]=='_')
					++i;
				cout << "<em>";
			} else if (mode == MODE_ITALIC && (buffer[i] == '*' || strncmp(buffer+i,"__",2) == 0 )) {
				mode = MODE_STD;
				if (buffer[i]=='_')
					++i;
				cout << "</em>";
			} else if (mode == MODE_ITALIC) {
				putchar(buffer[i]);
			/////////////////// inline verbatim ////////////////
			} else if ((mode == MODE_STD || mode == MODE_START) && buffer[i] == '`') {
				mode = MODE_INLINE_VERBATIM;
				cout << "<em>";
			} else if (mode == MODE_INLINE_VERBATIM && buffer[i] == '`') {
				mode = MODE_STD;
				cout << "</em>";
			} else if (mode == MODE_INLINE_VERBATIM) {
				putchar(buffer[i]);
			/////////////////// STANDARD TEXT //////////////////
			} else if (mode == MODE_STD) {
				putchar(buffer[i]);
			////////////////////   ERROR   /////////////////////
			} else {
				cerr << "Parsing error : " << buffer << endl;
				cerr << "Current mode is " << mode << endl;
				abort();
			}
			++i;
		}
	}
	cout << "**/" << endl;
	return EXIT_SUCCESS;
}

/******************* FUNCTION ********************/
int main(int argc, char ** argv)
{
	FILE * fp = NULL;
	//check args
	if (argc == 1)
	{
		fprintf(stderr,"Usage: %s {file.md}",argv[0]);
		return EXIT_FAILURE;
	}

	//openfile
	fp = fopen(argv[1],"r");
	if (fp != NULL)
	{
		convert_file(fp,argv[1]);
		fclose(fp);
		return EXIT_SUCCESS;
	} else {
		perror(argv[1]);
		return EXIT_FAILURE;
	}
}
