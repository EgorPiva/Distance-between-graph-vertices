#ifndef GRAPHDIALOG_H
#define GRAPHDIALOG_H

#include <QDialog>
#include "../../common/math/graph.h"

namespace Ui {
class GraphDialog;
}

class GraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphDialog(QWidget *parent = nullptr);
    ~GraphDialog();

private slots:
    void on_addVertexButton_clicked();
    void on_addEdgeButton_clicked();
    void on_findPathButton_clicked();
    void on_clearButton_clicked();
    void updateVertexList();

private:
    Ui::GraphDialog *ui;
    Graph graph;
};

#endif // GRAPHDIALOG_H 