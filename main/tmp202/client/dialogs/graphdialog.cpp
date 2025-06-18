#include "graphdialog.h"
#include "ui_graphdialog.h"
#include <QMessageBox>
#include <QDebug>

GraphDialog::GraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphDialog)
{
    ui->setupUi(this);
    setWindowTitle("Поиск кратчайшего пути в графе");
    updateVertexList();
}

GraphDialog::~GraphDialog()
{
    delete ui;
}

void GraphDialog::on_addVertexButton_clicked()
{
    int vertex = ui->vertexSpinBox->value();
    
    if (graph.getVertices().contains(vertex)) {
        QMessageBox::warning(this, "Ошибка", "Вершина с таким номером уже существует");
        return;
    }
    
    graph.addVertex(vertex);
    updateVertexList();
    
    ui->vertexSpinBox->setValue(vertex + 1);
}

void GraphDialog::on_addEdgeButton_clicked()
{
    if (ui->fromVertexComboBox->count() == 0 || ui->toVertexComboBox->count() == 0) {
        QMessageBox::warning(this, "Ошибка", "Добавьте хотя бы две вершины");
        return;
    }
    
    int from = ui->fromVertexComboBox->currentText().toInt();
    int to = ui->toVertexComboBox->currentText().toInt();
    double weight = ui->weightSpinBox->value();
    
    if (from == to) {
        QMessageBox::warning(this, "Ошибка", "Нельзя добавить ребро в ту же вершину");
        return;
    }
    
    // Проверяем, не существует ли уже такое ребро
    if (graph.getEdgeWeight(from, to) != std::numeric_limits<double>::infinity()) {
        QMessageBox::warning(this, "Ошибка", "Такое ребро уже существует");
        return;
    }
    
    graph.addEdge(from, to, weight);
    
    // Обновляем список рёбер
    QString edge = QString("%1 - %2 (%3)").arg(from).arg(to).arg(weight);
    ui->edgesListWidget->addItem(edge);
}

void GraphDialog::on_findPathButton_clicked()
{
    if (ui->startVertexComboBox->count() == 0 || ui->endVertexComboBox->count() == 0) {
        QMessageBox::warning(this, "Ошибка", "Добавьте хотя бы две вершины");
        return;
    }
    
    int start = ui->startVertexComboBox->currentText().toInt();
    int end = ui->endVertexComboBox->currentText().toInt();
    
    if (start == end) {
        QMessageBox::warning(this, "Ошибка", "Начальная и конечная вершины не могут совпадать");
        return;
    }
    
    auto result = graph.findShortestPath(start, end);
    
    if (result.success) {
        QString pathStr;
        for (int i = 0; i < result.path.size(); ++i) {
            if (i > 0) pathStr += " -> ";
            pathStr += QString::number(result.path[i]);
        }
        
        ui->resultLabel->setText(QString("Кратчайший путь: %1\nДлина пути: %2")
                               .arg(pathStr)
                               .arg(result.distance));
    } else {
        ui->resultLabel->setText("Ошибка: " + result.errorMessage);
    }
}

void GraphDialog::on_clearButton_clicked()
{
    graph.clear();
    ui->edgesListWidget->clear();
    ui->resultLabel->clear();
    updateVertexList();
}

void GraphDialog::updateVertexList()
{
    QVector<int> vertices = graph.getVertices();
    
    // Обновляем все комбобоксы с вершинами
    ui->fromVertexComboBox->clear();
    ui->toVertexComboBox->clear();
    ui->startVertexComboBox->clear();
    ui->endVertexComboBox->clear();
    
    for (int vertex : vertices) {
        QString vertexStr = QString::number(vertex);
        ui->fromVertexComboBox->addItem(vertexStr);
        ui->toVertexComboBox->addItem(vertexStr);
        ui->startVertexComboBox->addItem(vertexStr);
        ui->endVertexComboBox->addItem(vertexStr);
    }
} 