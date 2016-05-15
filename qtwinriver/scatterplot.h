#ifndef SCATTERPLOT_H
#define SCATTERPLOT_H
#include <QWidget>
class Plot;

class ScatterPlot: public QWidget
{
    Q_OBJECT

public:
    ScatterPlot();

private:
    void setSamples( int samples );

private:
    Plot *d_plot;
};
#endif // SCATTERPLOT_H

