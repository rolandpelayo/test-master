var x = setInterval(function(){loadData("data.txt", updateData)}, 200);

function loadData(url, callback){
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			callback.apply(xhttp);
		}
	};
	xhttp.open("GET", url, true);
	xhttp.send();
}
function updateData(){
	document.getElementById("data").innerHTML = this.responseText;
	if(parseFloat(this.responseText) < 920)
	{
		document.getElementById("data2").innerHTML = "Not Dark";
	}
	if(parseFloat(this.responseText) >= 920 && parseFloat(this.responseText) < 950 ){
		document.getElementById("data2").innerHTML = "Dark";
	}
	if(parseFloat(this.responseText) >= 950 && parseFloat(this.responseText) < 1000)
	{
		document.getElementById("data2").innerHTML = "Darker";
	}
	if(parseFloat(this.responseText) >= 1000)
	{
		document.getElementById("data2").innerHTML = "Darkest";
	} 
}
