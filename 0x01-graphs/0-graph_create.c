#include "graphs.h"

/**
 * graph_create - creates a graph
 *
 * Return: node to the graph, otherwise return NULL
 */

graph_t *graph_create(void)
{
	graph_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->nb_vertices = 0;
	new->vertices = NULL;
	return (new);
}
