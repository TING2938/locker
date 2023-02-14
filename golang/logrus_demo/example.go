package main

import (
	log "github.com/sirupsen/logrus"
	"gopkg.in/natefinch/lumberjack.v2"
)

func main() {
	testLog := log.New()
	testLog.SetOutput(&lumberjack.Logger{
		Filename:   "./testlogrus.log",
		MaxSize:    500,  // 日志文件大小，单位是 MB
		MaxBackups: 3,    // 最大过期日志保留个数
		MaxAge:     28,   // 保留过期文件最大时间，单位 天
		Compress:   true, // 是否压缩日志，默认是不压缩。这里设置为true，压缩日志
	})
	testLog.SetFormatter(&log.TextFormatter{
		DisableColors:   true,
		TimestampFormat: "2006-01-02 15:04:05",
	})
	i := 4
	testLog.SetLevel(log.Level(i))

	// testLog.Fatal("hello world")
	testLog.Error("hello world")
	testLog.Info("hello world")
}
