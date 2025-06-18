#ifndef BISECTIONMETHOD_H
#define BISECTIONMETHOD_H

#include <QString>
#include <QVector>
#include <functional>

class BisectionMethod {
public:
    BisectionMethod();
    
    // Структура для результата решения
    struct Result {
        bool success;
        double root;
        int iterations;
        double precision;
        QString errorMessage;
    };
    
    // Решает уравнение методом деления пополам
    static Result solveEquation(const QString &equation, double a, double b, double epsilon = 0.0001, int maxIterations = 100);
    
    // Решает уравнение методом деления пополам с использованием функции
    static Result solve(const std::function<double(double)> &func, double a, double b, double epsilon = 0.0001, int maxIterations = 100);
    
private:
    // Парсит строку уравнения и возвращает функцию для вычисления
    static std::function<double(double)> parseEquation(const QString &equation, bool &success, QString &errorMessage);
};

#endif // BISECTIONMETHOD_H 