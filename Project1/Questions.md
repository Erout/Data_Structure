# Qt
## qstring to c++ string
QString qs;

// Either this if you use UTF-8 anywhere
std::string utf8_text = qs.toUtf8().constData();

// or this if you're on Windows :-)
std::string current_locale_text = qs.toLocal8Bit().constData();

## 发布程序
编译release版本，从release目录中将.exe和.dll复制到一份文件夹