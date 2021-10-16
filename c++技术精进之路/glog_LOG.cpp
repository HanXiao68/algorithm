//////
//////  glog_LOG.cpp
//////  程序喵
//////
//////  Created by 韩霄 on 2021/10/2.
//////
//#include <vector>
//#include <string>
//#include <iostream>
//#include <glog/logging.h>
////
////using namespace std;
////
//
//
//class LogMessage {
//    struct  LogMessageData {
//        LogMessageData();
//        int preserved_errno_; //保留的错误号
//        //bufferKO哪个键：包含了完整的message 的文本字段信息
//        char mesage_text_ {static_cast<char>(LogMessage::kMaxLogMessageLen+1)};
//        LogStream stream_; //std::ostream
//        char serverity; //要使用的是什么log等级
//        int line_;// log的行号，当log被调用的时候的行号
//        void (LogMessage::*send_method_) (); //析构器被传送的时候调用这个。
//        union {
//            LogSink* sink_;
//            std::vector<std::string>* outvec_;//存放message的容器
//            std::string* message_;//使用string来存放message
//        };
//        LogMessageData::LogMessageData()
//            : stream_(message_text_,LogMessage::kMaxLogMessageLen,0){}
//        
//        time_t timestamp_; //创建log的时间
//        struct ::tm tm_time;//创建log的时间。
//    };
//    LogMessageData::LogStream stream_;//自定义输出流
//
//
//    LogMessageData* allocated_;//LogMessageData的主要结构体
//    LogMessageData* data_;
//    size_t num_prefix_chars_; //log中message的前缀长度
//    size_t num_chars_to_log_; //log的总长度
//    size_t num_chars_to_syslog_; //syslog的总长度
//    const char* basename_;//log文件的简写名称
//    const char* fullname_;//log文件的全部名称
//    bool has_been_flushed; //log文件没有flush （false），反之flush成功
//    bool first_fatal_; // log中首条 fatal  （true）
//    
//    
//
//    
//private:
//    LogMessageData(const LogMessageData&);
//    void operator= {const LogMessageData&};
//    struct LogMessageData;
//
//};
//
//
//
//
//
////
//int main(int argc, char* argv[]) {
////    官方给的glog的案例
////    // Initialize Google’s logging library.
////    google::InitGoogleLogging(argv[0]);
////
////    // ...
////    LOG(INFO) << "Found ";
//}
