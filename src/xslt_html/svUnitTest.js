/*****************************************************
             PROJECT  : svmath
             VERSION  : 0.0.1
             DATE     : 08/2009
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

function filterTests(status,tests)
{
	invert=false;

	if (status[0]=='!')
	{
		invert = true;
		status = status.substring(1,status.length);
	}

	cnt=0;
	for (k=0;k<tests.length;k++)
	{
		found = tests[k].className == status || status == '*';
		if (invert)
			found = !found;
		if (found)
		{
			tests[k].style.display="list-item";
			cnt++;
		} else {
			tests[k].style.display="none";
		}
	}
	return cnt;
}

function filterSuite(status,suite)
{
	for (j=0;j<suite.childNodes.length;j++)
	{
		if (suite.childNodes[j].className == 'tests')
		{
			if (filterTests(status,suite.childNodes[j].childNodes)==0)
				suite.style.display="none";
			else
				suite.style.display="block";
		}
	}
}

function showOnly(status)
{
	body = document.getElementById('body');
	suites = body.childNodes;
	for (i=0;i<suites.length;i++)
	{
		if (suites[i].className == 'suite')
			filterSuite(status,suites[i]);
	}
}
