function submit_by_id() 
{
var username = document.getElementById("username").value;
var password = document.getElementById("password").value;
document.getElementById("form_id").submit();
alert(" Userame : " + username + " \n Password : " + password);
}