bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -std=c++17 -o bin/testTableEntry testTableEntry.cpp

bin/testHashTable: testHashTable.cpp HashTable.h
	mkdir -p bin
	g++ -std=c++17 -o bin/testHashTable testHashTable.cpp


bin/testBSTree: testBSTree.cpp BSTree.h
	mkdir -p bin
	g++ -std=c++17 -o bin/testBSTree testBSTree.cpp

bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h
	mkdir -p bin
	g++ -std=c++17 -o bin/testBSTreeDict testBSTreeDict.cpp




clean:
	rm -rf *.o *.gch bin
