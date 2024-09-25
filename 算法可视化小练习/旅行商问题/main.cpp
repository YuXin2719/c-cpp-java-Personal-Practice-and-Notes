#include <QApplication>      //应用程序类
#include <QMainWindow>       //主窗口类
#include <QPainter>          //绘图类
#include <QTimer>            //定时器类

#include <random>            //随机数生成器
#include <vector>            //向量容器
#include <cmath>             //数学函数
#include <limits>            //数值极限

// 城市类
class City {
public:
    int x;
    int y;

    City(int x, int y)
        : x(x), y(y) {}
};

// TSP 求解类
class TSP {
public:
    void initCities(int numCities, int maxX, int maxY) {
        std::random_device rd;                    // 随机数种子
        std::mt19937 gen(rd());                   // Mersenne Twister 随机数引擎
        std::uniform_int_distribution<> disX(0, maxX);   // X 坐标的均匀分布随机数生成器
        std::uniform_int_distribution<> disY(0, maxY);   // Y 坐标的均匀分布随机数生成器

        cities.clear();                           // 清空城市向量
        for (int i = 0; i < numCities; ++i) {     // 遍历生成指定数量的城市坐标
            int x = disX(gen);                    // 生成随机的 x 坐标
            int y = disY(gen);                    // 生成随机的 y 坐标
            cities.emplace_back(x, y);            // 将城市坐标加入城市向量
        }

        distanceMatrix.resize(numCities, std::vector<double>(numCities));  // 调整距离矩阵大小
        for (int i = 0; i < numCities; ++i) {
            for (int j = 0; j < numCities; ++j) {
                if (i == j) {
                    distanceMatrix[i][j] = 0;         // 城市自身与自身的距离为0
                }
                else {
                    int dx = cities[i].x - cities[j].x;   // 计算 x 坐标差
                    int dy = cities[i].y - cities[j].y;   // 计算 y 坐标差
                    distanceMatrix[i][j] = std::sqrt(dx * dx + dy * dy);  // 计算距离并存入距离矩阵
                }
            }
        }

        currentPath.clear();             // 清空当前路径
        bestPath.clear();                // 清空最佳路径
        bestDistance = std::numeric_limits<double>::max();  // 初始化最佳距离为最大值

        visited.resize(numCities, false);  // 初始化城市访问标记向量
    }

    void solveStep() {
        // 如果路径还未初始化，则初始化路径
        if (currentPath.empty()) {
            int startCity = 0;                // 从城市0开始
            currentPath.push_back(startCity);  // 将起始城市加入当前路径
            visited[startCity] = true;         // 标记起始城市已访问
        }

        // 检查是否还有未访问的城市
        if (currentPath.size() < cities.size()) {
            int currentCity = currentPath.back();    // 获取当前路径的最后一个城市
            int nextCity = findNextCity(currentCity); // 查找下一个未访问的最近城市
            if (nextCity != -1) {
                currentPath.push_back(nextCity);     // 将找到的下一个城市加入当前路径
                visited[nextCity] = true;            // 标记该城市已访问
            }
        }

        // 如果所有城市都被访问过，检查是否完成了循环
        if (currentPath.size() == cities.size()) {
            int startCity = currentPath.front();       // 起始城市
            int lastCity = currentPath.back();         // 最后一个城市
            double lastToFirstDistance = distanceMatrix[lastCity][startCity];  // 计算最后一个城市到起始城市的距离
            if (lastToFirstDistance != 0) {            // 确保不是重复计算距离
                currentPath.push_back(startCity);      // 完成路径闭合
            }

            double totalDistance = calculateTotalDistance(currentPath);  // 计算当前路径总距离
            if (totalDistance < bestDistance || bestPath.empty()) {
                bestPath = currentPath;               // 更新最佳路径
                bestDistance = totalDistance;         // 更新最佳距离
            }
        }
    }

    const std::vector<int>& getCurrentPath() const {
        return currentPath;                // 返回当前路径
    }

    const std::vector<int>& getBestPath() const {
        return bestPath;                   // 返回最佳路径
    }

    const std::vector<City>& getCities() const {
        return cities;                     // 返回城市向量
    }

private:
    std::vector<City> cities;             // 城市向量
    std::vector<std::vector<double>> distanceMatrix;  // 距离矩阵
    std::vector<int> currentPath;         // 当前路径
    std::vector<int> bestPath;            // 最佳路径
    double bestDistance = std::numeric_limits<double>::max();  // 最佳距离
    std::vector<bool> visited;            // 记录城市是否被访问过的标记向量

    int findNextCity(int currentCity) {
        int nextCity = -1;                // 用作标记，尚未找到符合条件的下一个城市
        double minDistance = std::numeric_limits<double>::max();  // 模板函数，最小距离初始值为最大值
        for (int i = 0; i < cities.size(); ++i) {
            if (!visited[i]) {
                double distance = distanceMatrix[currentCity][i];  // 计算当前城市到下一个未访问城市的距离
                if (distance < minDistance) {
                    minDistance = distance;         // 更新最小距离
                    nextCity = i;                   // 更新下一个城市索引
                }
            }
        }
        return nextCity;                    // 返回下一个城市索引
    }

    double calculateTotalDistance(const std::vector<int>& path) {
        double totalDistance = 0;           // 总距离初始值为0
        for (size_t i = 0; i < path.size() - 1; ++i) {
            totalDistance += distanceMatrix[path[i]][path[i + 1]];  // 计算路径中每两个城市之间的距离并累加
        }
        // 添加最后一个城市回到第一个城市的距离
        totalDistance += distanceMatrix[path[path.size() - 1]][path[0]];
        return totalDistance;               // 返回总距离
    }
};

// 主窗口类
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {
        tsp.initCities(10, width(), height());  // 初始化 TSP 求解器，生成随机城市，10个城市

        setFixedSize(800, 600);             // 设置窗口固定大小
        setWindowTitle("可视化旅行商问题");  // 设置窗口标题

        timer = new QTimer(this);           // 创建定时器对象

        //timer Qtimer对象实例  &QTimer::timeout 信号指针  MainWindow类
        // &MainWindow::updateGUI成员函数指针     指向MainWindow类的updateGUI槽函数。当timeout信号被触发时，updateGUI函数将会被执行
        connect(timer, &QTimer::timeout, this, &MainWindow::updateGUI);  // 连接定时器的 timeout 信号到 updateGUI 槽函数
        timer->start(1000);                 // 启动定时器，间隔 1 秒触发一次
    }

private slots:  //处理事件，异步通信
    void updateGUI() {
        tsp.solveStep();                   // 在每次定时器触发时，尝试解决路径的下一步
        update();                          // 触发重绘

        // 检查是否已经绘制完整条路径，然后停止定时器
        if (tsp.getBestPath().size() == tsp.getCities().size() + 1) {
            timer->stop();                 // 停止定时器
        }
    }

protected:
    void paintEvent(QPaintEvent* event) override {  //重写自定义绘图事件
        QPainter painter(this);            // 创建 QPainter（绘图设备） 对象，绘制当前窗口

        const auto& cities = tsp.getCities();  // 获取城市向量的引用 自动推导变量类型
        for (const auto& city : cities) {
            painter.drawEllipse(city.x - 5, city.y - 5, 10, 10);  // 绘制每个城市的圆形表示    调整中心点，圆形绘制左上角为起点
        }

        const auto& currentPath = tsp.getCurrentPath();  // 获取当前路径的引用
        if (currentPath.size() > 1) {   //起码是俩城市
            for (size_t i = 0; i < currentPath.size() - 1; ++i) {
                int from = currentPath[i];           // 当前路径中的起始城市索引
                int to = currentPath[i + 1];         // 当前路径中的目标城市索引
                painter.drawLine(cities[from].x, cities[from].y, cities[to].x, cities[to].y);  // 绘制路径线段
            }
        }

        const auto& bestPath = tsp.getBestPath();    // 获取最佳路径的引用
        if (!bestPath.empty() && bestPath.size() > 1) {     //
            QPen pen(Qt::red);                     // 创建红色画笔
            pen.setWidth(2);                       // 设置画笔宽度
            painter.setPen(pen);                   // 应用画笔设置
            for (size_t i = 0; i < bestPath.size() - 1; ++i) {
                int from = bestPath[i];            // 最佳路径中的起始城市索引
                int to = bestPath[i + 1];          // 最佳路径中的目标城市索引
                painter.drawLine(cities[from].x, cities[from].y, cities[to].x, cities[to].y);  // 绘制最佳路径线段
            }
        }
    }

private:
    TSP tsp;                                   // TSP 求解器对象
    QTimer* timer;                             // 定时器指针
};

#include "main.moc"                            // Qt 元对象编译器生成的文件，处理信号槽机制，自动调用Qt的moc工具

int main(int argc, char* argv[]) {  //接收和处理程序启动时用户传入的命令行参数
    QApplication app(argc, argv);              // 创建 Qt 应用程序对象

    MainWindow window;                         // 创建主窗口对象
    window.show();                             // 显示主窗口

    return app.exec();                         // 函数运行 Qt 应用的事件循环，循环结束返回整数表示退出
}
