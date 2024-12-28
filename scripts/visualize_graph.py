import networkx as nx
import json
import matplotlib.pyplot as plt

def generate_graph(graph_matrix):
    G = nx.Graph()

    for i, node in enumerate(graph_matrix):
        G.add_node(i)
        for j, edge in enumerate(node):
            if edge != 0:
                G.add_edge(i, j, label=edge)
    
    return G


def visualize_graph(graph_matrix):
    G = generate_graph(graph_matrix)
    
    pos = nx.spring_layout(G)
    nx.draw(G, pos, node_color='yellow', font_size=8, with_labels=True)

    edge_labels = nx.get_edge_attributes(G, 'label')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)
    plt.show()


if __name__ == '__main__':
    input_file = input("Enter the path to the input file: ")

    with open(input_file) as f:
        input_graph = input("Enter the name of the graph: ")
        data = json.load(f)
        graph = data[input_graph]
    
    visualize_graph(graph['matrix'])
