/*
接线说明:无

程序说明:使用闪存文件系统(SPIFFS)来对esp32s3的闪存写入的数据进行读操作

注意事项:无

函数示例:无

作者:灵首

时间:2023_3_11

*/
#include <Arduino.h>
#include <SPIFFS.h>
#include <FS.h>

String file_name = "test_esp32s3.txt";    //被读取的文件的地址及文件名



/*
# brief 启动SPIFFS
# param 无
# retval 无
*/
void SPIFFS_start_init(){
  if(SPIFFS.begin()){
    Serial.print("\nSPIFFS Start!!!");
  }
  else{
    Serial.print("\nSPIFFS Failed to start!!!");
  }
}



/*
# brief 检查在指定位置是否有对应的文件
# param 无
# retval 无
*/
void SPIFFS_document_scan(void){
  if(SPIFFS.exists(file_name)){
    Serial.print("\nSPIFFS document exists!!!\n");
  }
  else{
    Serial.print("\nSPIFFS document don't exists!!!\n");
  }

}


void setup() {

  Serial.begin(9600);
  Serial.print("...");

  SPIFFS_start_init();
  SPIFFS_document_scan();

  //打开指定的文件进行读操作并通过串口输出读取的文件内容
  File dataFile = SPIFFS.open(file_name,"r"); //建立File对象用于从SPIFFS中读取文件
  for (int i = 0; i < dataFile.size(); i++)
  {
    Serial.print((char)dataFile.read());    //不加(char) 会输出ASCII码
  }

  Serial.print("\n");

  // //打开指定的文件进行读操作并通过串口输出读取的文件内容
  // for (int i = 0; i < dataFile.size(); i++)
  // {
  //   Serial.print(dataFile.read());    //不加(char) 会输出ASCII码(应该是)
  // }
  
  dataFile.close();   //完成文件读取后关闭文件

  Serial.print("\nFinshed dealing data from SPIFFS");
}



void loop() {

}