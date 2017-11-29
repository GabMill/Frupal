/****************************************************
  * Programmer: Gabriel Miller
  * File: LandingPage.js
  * Description: Javascript for controlling the dropdown menu on the landing
  * page and redirecting to FrupalGame.html after passing map selection to
  * MapSwitcher.cgi
  **************************************************/

 //Dropdown functionality - shows/hides dropdown and changes button text
 //accordingly 
function dropdownClick()
{
    if (!event.target.matches('#dropdownButton'))
    {
        var dropdowns = document.getElementsByClassName("dropdownContent");
        var i;
        for (i = 0; i < dropdowns.length; i++)
        {
            var openDropdown = dropdowns[i];
            if (openDropdown.classList.contains('show'))
            {
                openDropdown.classList.remove('show');
            }
        }
    }
    document.getElementById("gameSelector").classList.toggle("show");
    var playButton = document.getElementById("dropdownButton");
    if(playButton.value == "Play game")
    {
        playButton.value = "Select a map to play"
    }
    else
    {
        playButton.value = "Play game"
    }
}

//Redirects page to FrupalGame.html after passing map selection to
//MapSwitcher.cgi
function redirect(arg)
{
    arguments = "map=" + arg + ".txt";
    var xhttp = new XMLHttpRequest();
    URL = "MapSwitcher.cgi?"+arguments;
    xhttp.open("GET", URL, true);
    xhttp.send();
    window.location="FrupalGame.html";
}
