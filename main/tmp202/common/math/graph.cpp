#include "graph.h"
#include <QQueue>
#include <QPair>
#include <limits>

Graph::Graph() {
}

void Graph::addVertex(int vertex) {
    if (!adjacencyList.contains(vertex)) {
        adjacencyList[vertex] = QMap<int, double>();
    }
}

void Graph::addEdge(int from, int to, double weight) {
    addVertex(from);
    addVertex(to);
    adjacencyList[from][to] = weight;
    adjacencyList[to][from] = weight; // Для неориентированного графа
}

Graph::ShortestPathResult Graph::findShortestPath(int start, int end) {
    ShortestPathResult result;
    result.success = false;
    
    // Проверка существования вершин
    if (!adjacencyList.contains(start) || !adjacencyList.contains(end)) {
        result.errorMessage = "Указанные вершины не существуют в графе";
        return result;
    }
    
    // Инициализация
    QMap<int, double> distances;
    QMap<int, int> previous;
    QVector<int> unvisited;
    
    // Установка начальных расстояний
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        distances[it.key()] = std::numeric_limits<double>::infinity();
        unvisited.append(it.key());
    }
    distances[start] = 0;
    
    // Основной цикл алгоритма Дейкстры
    while (!unvisited.isEmpty()) {
        // Находим вершину с минимальным расстоянием
        int current = unvisited[0];
        double minDist = distances[current];
        int minIndex = 0;
        
        for (int i = 1; i < unvisited.size(); ++i) {
            if (distances[unvisited[i]] < minDist) {
                minDist = distances[unvisited[i]];
                current = unvisited[i];
                minIndex = i;
            }
        }
        
        // Если достигли конечной вершины
        if (current == end) {
            result.success = true;
            result.distance = distances[end];
            
            // Восстанавливаем путь
            int vertex = end;
            while (vertex != start) {
                result.path.prepend(vertex);
                vertex = previous[vertex];
            }
            result.path.prepend(start);
            
            return result;
        }
        
        // Удаляем текущую вершину из непосещенных
        unvisited.removeAt(minIndex);
        
        // Обновляем расстояния до соседей
        for (auto it = adjacencyList[current].begin(); it != adjacencyList[current].end(); ++it) {
            int neighbor = it.key();
            double weight = it.value();
            
            if (distances[current] + weight < distances[neighbor]) {
                distances[neighbor] = distances[current] + weight;
                previous[neighbor] = current;
            }
        }
    }
    
    result.errorMessage = "Путь не найден";
    return result;
}

void Graph::clear() {
    adjacencyList.clear();
}

QVector<int> Graph::getVertices() const {
    return adjacencyList.keys().toVector();
}

double Graph::getEdgeWeight(int from, int to) const {
    if (adjacencyList.contains(from) && adjacencyList[from].contains(to)) {
        return adjacencyList[from][to];
    }
    return std::numeric_limits<double>::infinity();
} 