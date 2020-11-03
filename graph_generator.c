/* 
 * Graph generator (v1.1)
 * 
 * Generates a ".net" file with an automated algorithm.
 */

#include <stdio.h>

int main(){
	int verticesNum, arcStart, arcEnd, arcCounter;
	verticesNum = arcStart = arcEnd = arcCounter = 0;
	FILE *graphFile, *arrayFile;

	printf("Number of vertices: ");
	scanf("%d", &verticesNum);
	printf("\n");

// Files generation. "GRAPH.NET" and "ARRAY.TXT" files are generated. Every time the program runs, these files are changed.
	graphFile = fopen("GRAPH.NET", "w");
	arrayFile = fopen("ARRAY.TXT", "w");

// Generation of the file's content
	fprintf(graphFile, "*Vertices %d\n", verticesNum);
	fprintf(graphFile, "*Arcs\n");
 
// The loop that generates the graph file
	for (arcStart = 1; arcStart < verticesNum; arcStart++){
		for (arcEnd = arcStart + 1; arcEnd < verticesNum + 1; arcEnd++){
			fprintf(graphFile, "%d %d\n", arcStart, arcEnd);
			arcCounter++;
		}
	}

// The loop that generates the array file
	for (arcStart = 1; arcStart < verticesNum + 1; arcStart++){
		fprintf(arrayFile, "1 ");
		for (arcEnd = arcStart + 1; arcEnd < verticesNum + arcStart; arcEnd++){
			fprintf(arrayFile, "1 ");
		}
		fprintf(arrayFile, "\n");
	}

// End of the file generation
	fclose(graphFile);
	fclose(arrayFile);
	printf("Number of arcs generated: %d\n", arcCounter);
	return 0;
}
