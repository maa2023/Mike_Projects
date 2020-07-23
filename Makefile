
a.out: main.o RegionLayout.o RegionGraph.o RegionAreaVertex.o RegionAreas.o RegionArea.o KeyValuePair.o InputHelper.o Config.o ClosenessDist.o
	g++ main.o RegionLayout.o RegionGraph.o RegionAreaVertex.o RegionAreas.o RegionArea.o KeyValuePair.o InputHelper.o Config.o ClosenessDist.o -o a.out

main.o: main.cpp
	g++ -c main.cpp
	
RegionLayout.o: RegionLayout.cpp RegionLayout.h
	g++ -c RegionLayout.cpp
		
RegionGraph.o: RegionGraph.cpp RegionGraph.h
	g++ -c RegionGraph.cpp	
	
RegionAreaVertex.o: RegionAreaVertex.cpp RegionAreaVertex.h
	g++ -c RegionAreaVertex.cpp	
	
RegionAreas.o: RegionAreas.cpp RegionAreas.h
	g++ -c RegionAreas.cpp	
	
RegionArea.o: RegionArea.cpp RegionArea.h
	g++ -c RegionArea.cpp	
	
KeyValuePair.o: KeyValuePair.cpp KeyValuePair.h
	g++ -c KeyValuePair.cpp	
	
InputHelper.o: InputHelper.cpp InputHelper.h
	g++ -c InputHelper.cpp	
	
Config.o: Config.cpp Config.h
	g++ -c Config.cpp
	
ClosenessDist.o: ClosenessDist.cpp ClosenessDist.h
	g++ -c ClosenessDist.cpp	
	
clean:
	rm *.o a.out
