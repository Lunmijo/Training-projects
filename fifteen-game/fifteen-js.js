/* 
****Fifteen game script version 1.0
****by Lunmijo 
02.03.2018
*/

var NumberTable = [], GameBox, ei, ej;

function swap(NumberTable, i1, j1, i2, j2) {
temp = NumberTable[i1][j1];
NumberTable[i1][j1] = NumberTable[i2][j2];
NumberTable[i2][j2] = temp;
}

window.onload = function() {
	Gamebox = document.getElementById("Gamebox");
	newGame();
	document.getElementById("newFifteenGameButton").onclick = newGame;
}

function cellClick(event) {

	var event = event || window.event,
		el = event.srcElement || event.target,
		i = el.id.charAt(0),
		j = el.id.charAt(2);

	if((i == ei && Math.abs(j - ej) == 1) || (j == ej && Math.abs(i - ei) == 1)) {					
		document.getElementById(ei + " " + ej).innerHTML = el.innerHTML;
		el.innerHTML = "";

		ei = i;
		ej = j;

		var isWin = true;
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				if (i + j != 6 && document.getElementById(i + " " + j).innerHTML != i*4 + j + 1) {
					isWin = false;
					break;
				}
				if(isWin) { 
					alert("You are win! You did it!"); 
				}
			}
}

function newGame() {		

	for(i = 0; i < 4; ++i) {
		NumberTable[i] = []
		for(j = 0; j < 4; ++j) {
			if(i + j != 6) {
				NumberTable[i][j] = i*4 + j + 1;
			}
			else {
				NumberTable[i][j] = " ";
			}
		}
	}

	ei = 3;
	ej = 3;

	for(i = 0; i < 1600; ++i) {
		switch(Math.round(3*Math.random())) {
			case 0: if(ei != 0) swap(NumberTable,ei,ej,--ei,ej); break; // up
			case 1: if(ej != 3) swap(NumberTable,ei,ej,ei, ++ej); break; // right
			case 2: if(ei != 3) swap(NumberTable,ei,ej,++ei,ej); break; // down
			case 3: if(ej != 0) swap(NumberTable,ei,ej,ei,--ej); // left
		}
	}

	var table = document.createElement("table"),
		tbody = document.createElement("tbody");					
	table.appendChild(tbody);

	for(i = 0; i < 4; ++i) {
		var row = document.createElement("tr");
		for(j = 0; j < 4; ++j){
			var cell = document.createElement("td");
				cell.id = i + " " + j;
				cell.onclick = cellClick;
				cell.innerHTML = NumberTable[i][j];
				row.appendChild(cell);
		}

		tbody.appendChild(row);					
	}

	if(Gamebox.childNodes.length == 1)
		Gamebox.removeChild(Gamebox.firstChild);	
	Gamebox.appendChild(table);	
}
