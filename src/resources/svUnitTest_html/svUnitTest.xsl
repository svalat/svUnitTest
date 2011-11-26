<?xml version="1.0"?>
<!--***************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
***************************************************-->
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
	<html>
	<head>
		<title>svUnitTest <xsl:apply-templates select='UnitTest/TestEnv/TestDate'/></title>
		<link rel="stylesheet" type="text/css" href="svUnitTest_html/svUnitTest.css" />
		<script language='javascript' src='svUnitTest_html/svUnitTest.js'></script>
	</head>
	<body>
		<div id='page'>
		<div id='header'></div>
		<div id='body'>
			<h1 class='title'>svUnitTest</h1>
			<xsl:apply-templates select='UnitTest/GlobalResults'/>
			<xsl:apply-templates select='UnitTest/TestCase'/>
		</div>
		<div id='footer'></div>
		</div>
		<script language='javascript'>
			showOnly("!success");
		</script>
	</body>
	</html>
</xsl:template>

<xsl:template match="TestCase">
	<div class='suite'>
		<h2><xsl:value-of select="./name"/></h2>
		<ul class='tests'>
			<xsl:apply-templates select='TestFunction'/>
		</ul>
	</div>
</xsl:template>

<xsl:template match="TestFunction">
	<li>
		<xsl:attribute name="class"><xsl:value-of select="status"/></xsl:attribute>
		<xsl:value-of select="name"/>
		<xsl:apply-templates select='AssertInfo'/>
	</li>
</xsl:template>

<xsl:template match="AssertInfo">
	<div class='assert'>
		<div class='location'><xsl:value-of select='location/file'/> : <xsl:value-of select='location/line'/></div>
		<div class='message'><xsl:value-of select='message'/></div>
		<xsl:apply-templates select='entries'/>
		<xsl:apply-templates select='context'/>
	</div>
	<xsl:apply-templates select='output'/>
</xsl:template>

<xsl:template match="entries">
	<table class='assertEntries'>
		<xsl:apply-templates select='entry'/>
	</table>
</xsl:template>

<xsl:template match="context">
	<table class='assertEntries'>
		<xsl:apply-templates select='entry'/>
	</table>
</xsl:template>

<xsl:template match="entry">
	<tr>
		<td><xsl:value-of select='@name'/></td>
		<td>:</td>
		<td><xsl:value-of select='.'/></td>
	</tr>
</xsl:template>

<xsl:template match="output">
	<pre class='testOutput'><xsl:value-of select='.'/></pre>
</xsl:template>

<xsl:template match="GlobalResults">
	<div class='summary'>
		<h2>Summary</h2>
		<table>
			<tr><th></th><th>Status</th><th>Nombre</th><th colspan='2'>Rapport</th></tr>
			<xsl:for-each select="result">
				<tr>
					<xsl:attribute name='class'><xsl:value-of select='@type'/></xsl:attribute>
					<td class='selector'>
						<a alt='show'>
							<xsl:attribute name='href'>javascript:showOnly('<xsl:value-of select='@type'/>');</xsl:attribute>
							<img src='svUnitTest_html/view.png' alt='show'/>
						</a>
					</td>
					<td><xsl:value-of select='@type'/></td>
					<td><xsl:value-of select='.'/></td>
					<td class='rapport_progress'>
						<div class='progress'>
							<div class='bar'>
								<xsl:attribute name='style'>width: <xsl:value-of select='round(100 * . div ../total)'/>%;</xsl:attribute>
							</div>
						</div>
					</td>
					<td>
						<xsl:value-of select='round(100 * . div ../total)'/> %
					</td>
				</tr>
			</xsl:for-each>
			<tr class='total'>
				<td>
					<a alt='show' href="javascript:showOnly('*');"><img src='svUnitTest_html/view.png' alt='show'/></a>
				</td>
				<td>
					<xsl:attribute name='class'><xsl:value-of select='status'/></xsl:attribute>
					total
				</td>
				<td>
					<xsl:attribute name='class'><xsl:value-of select='status'/></xsl:attribute>
					<xsl:value-of select='total'/>
				</td>
				<td>
					<xsl:attribute name='class'><xsl:value-of select='status'/></xsl:attribute>
					<font>
						<xsl:attribute name='class'><xsl:value-of select='status'/></xsl:attribute>
						<xsl:value-of select='status'/>
					</font>
				</td>
				<td>
					<xsl:attribute name='class'><xsl:value-of select='status'/></xsl:attribute>
					100 %
				</td>
				</tr>
		</table>
	</div>
</xsl:template>

</xsl:stylesheet>
