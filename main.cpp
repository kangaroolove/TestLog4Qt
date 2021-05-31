#include <QCoreApplication>
#include <log4qt/basicconfigurator.h>
#include <log4qt/logger.h>
#include <QDebug>
#include <log4qt/ttcclayout.h>
#include <QString>
#include <log4qt/fileappender.h>
#include <log4qt/logmanager.h>
#include <log4qt/loggerrepository.h>
#include <log4qt/simplelayout.h>
#include <log4qt/consoleappender.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#if 0
    Log4Qt::BasicConfigurator::configure();

    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();

    logger->debug("Hello, Log4Qt");
#endif

#if 1
    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
    Log4Qt::TTCCLayout *layout = new Log4Qt::TTCCLayout();
    layout->setName("My Layout");
    layout->setDateFormat("ISO8601");
    layout->activateOptions();

    QString file = a.applicationDirPath() + "/info.log";
    Log4Qt::FileAppender *fileAppend = new Log4Qt::FileAppender(layout, file, true);
    fileAppend->setName("My File appender");
    fileAppend->activateOptions();

    logger->addAppender(fileAppend);

    logger->setLevel(Log4Qt::Level::INFO_INT);

    Log4Qt::LogManager::setHandleQtMessages(true);
    qInfo("aaa");
    logger->info("This is a info message");

    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();
#endif

#if 0
    // 创建一个 TTCCLayout（输出时间、线程、Logger 以及消息内容）
    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
    Log4Qt::TTCCLayout *layout = new Log4Qt::TTCCLayout();
    layout->setName("My Layout");
    // layout->setCategoryPrefixing(false); // 禁用 logger 名称
    // layout->setContextPrinting(false); // 禁用嵌套的上下文信息
    //layout->setThreadPrinting(false); // 禁用线程名
    //layout->setDateFormat("ISO8601"); // 设置日期格式
    layout->activateOptions();

    // 创建一个 ConsoleAppender（将日志内容输出到控制台上）
    Log4Qt::ConsoleAppender *appender = new Log4Qt::ConsoleAppender(layout, Log4Qt::ConsoleAppender::STDOUT_TARGET);
    appender->setName("My Appender");
    appender->activateOptions();
    logger->addAppender(appender);

    logger->setLevel(Log4Qt::Level::DEBUG_INT);
    logger->debug("Hello, Log4Qt!");

    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();
#endif

    return a.exec();
}
