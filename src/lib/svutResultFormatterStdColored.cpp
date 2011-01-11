/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatterStdColored.h"
#include <iomanip>
#include <sstream>

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  HEADERS  *********************/
/**
 * Define some values for terminal coloring, this is used to define colors assciated to status.
 * @brief List of some terminal colors.
**/
enum svutStdColor
{
	/** Green colored text. **/
	SVUT_STD_COLOR_GREEN=32,
	/** Blue colored text. **/
	SVUT_STD_COLOR_BLUE=34,
	/** Orange colored text. **/
	SVUT_STD_COLOR_ORANGE=33,
	/** Red colored test. **/
	SVUT_STD_COLOR_RED=31,
	/** White colored text (default). **/
	SVUT_STD_COLOR_WHITE=0
};

/*******************  FUNCTION  *********************/
/**
 * Constructor of the class.
 * @param out Define the output stream to use.
**/
svutResultFormatterStdColored::svutResultFormatterStdColored(std::ostream& out)
	: svutResultFormatterStd(out)
{
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStdColored::printMethodAndStatus(std::ostream& out, std::string name, svutStatus status)
{
	//sprintf(buffer," * %-40s     [ %s ]\n",testName.c_str(),statusName.c_str());
	//               " \e[32m*\e[0m %-40s     [ \e[%dm%s\e[0m ]\n"
	out << setColor(SVUT_STD_COLOR_GREEN) <<  " * " << unsetColor()
		<< setw(40) << left << name << "     [ "
		<< setStatusColor(status) << svutStatusInfo::getStatusName(status) << unsetColor()
		<< " ]" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStdColored::printSummaryStat(std::ostream& out, svutStatus status, unsigned int nb, unsigned int tot)
{
	 //sprintf(buffer,"|  %-9s: %4d (%3d %%)  |\n",name,nb,100*nb/tot);
	 //               "|  \e[%dm%-9s: %4d (%3d %%)\e[0m  |\n"
	 unsigned int perc;

	 //calc percentage
	 if (tot == 0)
		 perc = 0;
	 else
		 perc = (100*nb)/tot;

	 //display
	 out << "|  "
		<< setStatusColor(status) << setw(9) << left << svutStatusInfo::getStatusName(status) << ": "
		<< setw(4) << right << nb << " (" << setw(3) << right << perc << " %)" << unsetColor()
		<< "  |" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStdColored::printSummaryFinalStatus(std::ostream& out, svutStatus status)
{
	//sprintf(buffer,"|  STATUS   : %-12s  |\n",name);
	//               "|  STATUS   : \e[%dm%-12s\e[0m  |\n"
	out << "|  STATUS   : " << setStatusColor(status) << setw(12) << left
		<< svutStatusInfo::getStatusName(status) << unsetColor() << "  |" << endl;
}

/*******************  FUNCTION  *********************/
/**
 * Return the color associated to the given status.
 * @param status Define the status for which we want the color.
 * @return Return the requested color.
**/
int svutResultFormatterStdColored::getStatusColor(svutStatus status) const
{
	int res = SVUT_STD_COLOR_WHITE;
	switch(status)
	{
		case SVUT_STATUS_SUCCESS:
			res = SVUT_STD_COLOR_GREEN;
			break;
		case SVUT_STATUS_TODO:
			res = SVUT_STD_COLOR_ORANGE;
			break;
		case SVUT_STATUS_INDEV:
			res = SVUT_STD_COLOR_BLUE;
			break;
		case SVUT_STATUS_FAILED:
			res = SVUT_STD_COLOR_RED;
			break;
		case SVUT_STATUS_UNKNOWN:
			res = SVUT_STD_COLOR_RED;
			break;
		case SVUT_STATUS_SKIPED:
			res = SVUT_STD_COLOR_ORANGE;
			break;
		default:
			throw svutExInternalError("Unknown status in svutResultFormatterStdColored::getStatusColor().");
			break;
	}
	return res;
}

/*******************  FUNCTION  *********************/
/**
 * Build the coloring chain for the terminal.
 * @param color Define the terminal color to use.
 * @return Return the sepcial chain as std::string.
**/
std::string svutResultFormatterStdColored::setColor(int color) const
{
	stringstream res;
	res << (char)27 << "[" << color << 'm';
	return res.str();
}

/*******************  FUNCTION  *********************/
/**
 * Build the coloring chain for the terminal.
 * @param status Define the status used to select the color.
 * @return Return the sepcial chain as std::string.
**/
string svutResultFormatterStdColored::setStatusColor(svutStatus status) const
{
	return setColor(getStatusColor(status));
}

/*******************  FUNCTION  *********************/
/**
 * Simply return the command to set color to default.
 * @return return the command to set color to default.
**/
string svutResultFormatterStdColored::unsetColor(void ) const
{
	return setColor(SVUT_STD_COLOR_WHITE);
}

}
