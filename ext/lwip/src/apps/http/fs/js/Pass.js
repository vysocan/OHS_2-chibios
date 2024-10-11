function pv(){
for(var i=0;i<tc.length;i++){
id=tc[i].id;
if(document.getElementById(id).value!=document.getElementById(id.toUpperCase()).value){
j=i+1;alert("Passwords do not match for "+j+". entry!");return false;}
}return true;}