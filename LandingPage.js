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
