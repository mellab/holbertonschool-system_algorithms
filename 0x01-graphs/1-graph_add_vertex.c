#include "graphs.h"

/**
 * init - initialize
 * @graph: graph to update
 * @str: string to store
 * @cur: last vertex in graph
 * @new: the new vertex
 *
 * Return: pointer to the new vertex, otherwise return NULL
 */

vertex_t *init(graph_t *graph, const char *str, vertex_t *cur, vertex_t *new)
{
	++graph->nb_vertices;
	if (!cur)
	{
		graph->vertices = new;
		new->index = 0;
	}
	else
	{
		cur->next = new;
		new->index = cur->index + 1;
	}
	new->content = strdup(str);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->nb_edges = 0;
	new->edges = NULL;
	new->next = NULL;
	return (new);
}

/**
 * graph_add_vertex - add vertex
 * @graph: pointer to graph to add vertex to
 * @str: string to store in new vertex
 *
 * Return: pointer to new vertex, otherwise return NULL
 */

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new, *cur;

	if (!graph || !str)
		return (NULL);
	for (cur = graph->vertices; cur; cur = cur->next)
	{
		if (!strcmp(cur->content, str))
			return (NULL);
		if (!cur->next)
			break;
	}
	new = malloc(sizeof(*new));
	return (!new ? NULL : init(graph, str, cur, new));
}
