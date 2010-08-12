/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatterStdBW.h"
#include <iomanip>

using namespace std;

namespace svUnitTest
{

/********************  METHODE  *********************/
/**
 * Constructor of the class.
 * @param out Define the output stream to use.
**/
svutResultFormatterStdBW::svutResultFormatterStdBW(std::ostream& out)
	: svutResultFormatterStd(out)
{
}

/********************  METHODE  *********************/
void svutResultFormatterStdBW::printMethodAndStatus(std::ostream& out, std::string name, svutStatus status)
{
	//sprintf(buffer," * %-40s     [ %s ]\n",testName.c_str(),statusName.c_str());

	out << " * " << setw(40) << left << name
		<< "     [ " << svutStatusInfo::getStatusName(status) << " ]" << endl;
}

/********************  METHODE  *********************/
void svutResultFormatterStdBW::printSummaryStat(std::ostream& out, svutStatus status, unsigned int nb, unsigned int tot)
{
	 //sprintf(buffer,"|  %-9s: %4d (%3d %%)  |\n",name,nb,100*nb/tot);
	 unsigned int perc;

	 //calc percentage
	 if (tot == 0)
		 perc = 0;
	 else
		 perc = (100*nb)/tot;

	 //display
	 out << "|  " << setw(9) << left << svutStatusInfo::getStatusName(status) << ": "
		<< setw(4) << right << nb << " (" << setw(3) << right << perc << " %)  |" << endl;
}

/********************  METHODE  *********************/
void svutResultFormatterStdBW::printSummaryFinalStatus(std::ostream& out, svutStatus status)
{
	//sprintf(buffer,"|  STATUS   : %-12s  |\n",name);
	out << "|  STATUS   : " << setw(12) << left << svutStatusInfo::getStatusName(status) << "  |" << endl;
}

}
