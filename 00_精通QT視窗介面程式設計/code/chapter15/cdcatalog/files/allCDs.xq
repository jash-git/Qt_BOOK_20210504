(: Select all cds. :)
declare variable $inputDocument external;
	<html>
		<meta http-equiv="content-type" content="text/html; charset=utf-8" />
  	<body>
  	<h2>我的CD收藏</h2>
  	<table border="1">
      <tr bgcolor="#9acd32">
        <th align="center">單曲</th>
        <th align="center">藝術家</th>
        <th align="center">國籍</th>
        <th align="center">出版商</th>
        <th align="center">出版時間</th>
        <th align="center">單價(元)</th>
      </tr>
	{
		doc($inputDocument)/catalog/cd/
      <tr>
        <td> {name} </td>
        <td> {artist} </td>
        <td> {country} </td>
        <td> {company} </td>
        <td> {year} </td>
        <td> {price}</td>
      </tr>
	}

  		</table>
  	</body>
	</html>	