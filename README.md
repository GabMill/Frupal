# Frupal
ID      NAME/Description            PROTOTYPE DISPLAY       FINAL DISPLAY       PROTOYPED?      ASSET LOADED
***************************************************************************************************************
play:   Player                      duck.png                player.png          yes             yes

**CELLS**
mea:    Meadow                      #ADFF2F                 meadow.png          yes             no
for:    Forest                      #228B22                 forest.png          yes             no
wat:    Water                       #1E90FF                 water.gif           yes             no
wal:    Wall                        #696969                 wall.png            yes             no
bog:    Bog                         #3CB371                 bog.gif             yes             no
swa:    Swamp                       #6B8E23                 swamp.png           yes             no
fog:    Fog                         n/a                     fog.gif             yes             yes

**OBJECTS**
obj0:   None                        n/a                     n/a                 no              n/a
obj1:   Tree                        Tr                      tree.png            no              no
obj2:   Boulder                     Bo                      boulder.png         no              no
obj3:   Blackberry Bushes           BB                      bush.png            no              no
obj4:   Power Bar                   PB                      powerbar.png        no              no
obj5:   Type 1 Treasure Chest       1                       chest1.png          no
obj6:   Type 2 Treasure Chest       2                       chest2.png          no
obj7:   Royal Diamonds              D                       diamond.png         no
obj8:   Clue                        ?                       clue.png            no

**ITEMS**
itm0:   Hatchet                     Ha                      hatchet.png         no
itm1:   Axe                         Ax                      axe.png             no
itm2:   Chainsaw                    Cs                      chainsaw.png        no
itm3:   Chisel                      Ch                      chisel.png          no
itm4:   Sledge                      Sl                      sledge.png          no
itm5:   Jackhammer                  Ja                      jackhammer.png      no
itm6:   Machete                     Ma                      machete.png         no
itm7:   Shears                      Sh                      shears.png          no
itm8:   Binoculars                  Bi                      binoculars.png      no

**TERMS**
MAX:    The number determining the dimensions of the map.

***************************************************************************************************************

PROCESS
1.  Find where the player is on the map.
2.  Check if the player has binoculars
3.  Calculate all cells adjacent to this space.
    a.  Set every adjacent cell visiblity to true.
4.  Calculate all diagonal cells to this space.
    a.  Set every diagonal cell visibility to true.
5.  Draw the cells
6.  Draw the objects on top of the previous map.
7.  Draw the items on top of the previous map.
8.  Draw the player on top of the previous map.
