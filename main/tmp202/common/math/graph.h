#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QString>
#include <QMap>

class Graph {
public:
    Graph();
    
    // Структура для результата поиска кратчайшего пути
    struct ShortestPathResult {
        bool success;
        double distance;
        QVector<int> path;
        QString errorMessage;
    };
    
    // Добавление вершины
    void addVertex(int vertex);
    
    // Добавление ребра
    void addEdge(int from, int to, double weight);
    
    // Поиск кратчайшего пути между двумя вершинами (алгоритм Дейкстры)
    ShortestPathResult findShortestPath(int start, int end);
    
    // Очистка графа
    void clear();
    
    // Получение списка вершин
    QVector<int> getVertices() const;
    
    // Получение веса ребра
    double getEdgeWeight(int from, int to) const;
    
private:
    QMap<int, QMap<int, double>> adjacencyList; // Список смежности с весами
};

#endif // GRAPH_H 