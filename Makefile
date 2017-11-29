full: Move.cgi DisplayState.cgi Inventory.cgi Display.cgi Purchase.cgi

Move.cgi: MovementChecker.c MovementCombiner.c Map.c Player.c DiamondFinder.c
	gcc MovementChecker.c MovementCombiner.c Map.c Player.c Save.c DiamondFinder.c -lcgi
	mv a.out Move.cgi

DisplayState.cgi: DisplayState.c Player.c
	gcc DisplayState.c Player.c
	mv a.out DisplayState.cgi

Inventory.cgi: PlayerInventory.c Player.c
	gcc PlayerInventory.c Player.c
	mv a.out Inventory.cgi

Display.cgi: MapDisplay.c Map.c Player.c Save.c
	gcc MapDisplay.c Map.c Player.c Save.c
	mv a.out Display.cgi

Purchase.cgi: Purchase.c Player.c Map.c
	gcc Purchase.c Player.c Map.c Save.c
	mv a.out Purchase.cgi

clean:
	rm *.cgi
