function load(){
	var a=document.getElementById("article").offsetHeight ;
	var b=document.getElementById("navigation").offsetHeight ;
	if (a<b) {
		document.getElementById("content").style.height = b + "px";
	}
	else{
		document.getElementById("content").style.height = a + "px";
	}
	/*var list = document.getElementsByClassName("content");
	for (var i = 0; i < list.length; i++) {
		for (var k = 0; k < list[i].children[0].childElementCount; k++) {
			list[i].children[0].children[k].onclick = bouton;
		}
	}
	*/
}
function bouton(sender){
	var list_collapsible = document.getElementsByClassName("collapsible");
	var list_content = document.getElementsByClassName("content");
	var t = 0;
	for (var i = 0; i < list_collapsible.length; i++) {
		if(list_collapsible[i] == sender){
			t = i;
		}
	}
	if (list_content[t].style.display === "block") {
	      list_content[t].style.display = "none";
	    } else {
	      list_content[t].style.display = "block";
	    }
}