#ifndef EM9636_H
#define EM9636_H

#define EM9636_USB_MAX_COUNT                        16 //最大可支持USB模块个数
#define EM9636_BASE_FREQ                            16000000.0//基础时钟，16M
#define EM9636_MAXADCHCNT                           32 //AD最大通道数
#define EM9636_MAXIOCHCNT                           32 //IO最大通道数
#define EM9636_MAXCTCHCNT                           6 //计数器最大通道数
#define EM9636_MAXECCHCNT                           2 //编码器最大通道数
#define EM9636_MAXPWMCHCNT                          3 //编码器最大通道数

//启动方式
#define EM9636_STARTMODE_ICLK                       0 //内时钟启动采集
#define EM9636_STARTMODE_ECLK                       1 //外时钟启动采集

//伪同步控制
#define EM9636_PSYNC_NO								0 //伪同步无效
#define EM9636_PSYNC_YES							1 //伪同步有效

//触发源
#define EM9636_TRI_IN								0 //内部
#define EM9636_TRI_EXTERN							1 //外部

//触发方式
#define EM9636_TRI_UPEDGE							0 //上升沿
#define EM9636_TRI_HIGHLEVEL						1 //高电平
#define EM9636_TRI_DOWNEDGE							2 //下降升沿
#define EM9636_TRI_LOWLEVEL							3 //低电平

//AD采集范围
#define EM9636_AD_RANGE_N10_10V                      0L //±10V
#define	EM9636_AD_RANGE_N5_5V                        1L //±5V
#define	EM9636_AD_RANGE_0_10V                        2L //0~10V
#define	EM9636_AD_RANGE_0_5V                         3L //0~5V
#define	EM9636_AD_RANGE_0_20mA                       4L //0~20mA

//AD单端还是差分
#define	EM9636_AD_SINGLE                             0L //单端
#define	EM9636_AD_DIFF                               1L //差分

//AD增益
#define EM9636_AD_GAIN_1                             0 //1倍增益
#define EM9636_AD_GAIN_2                             1 //2倍增益
#define EM9636_AD_GAIN_5                             2 //5倍增益
#define EM9636_AD_GAIN_10                            3 //10倍增益

//DA采集范围
#define EM9636_DA_RANGE_N10_10V                      0L //±10V
#define	EM9636_DA_RANGE_N5_5V                        1L //±5V
#define	EM9636_DA_RANGE_0_10V                        2L //0~10V
#define	EM9636_DA_RANGE_0_5V                         3L //0~5V

//DA输出方式
#define EM9636_DA_MODE_CODE                          0L //原码值输出
#define	EM9636_DA_MODE_VALUE                         1L //电压值输出（mV）

//计数方式
#define EM9636_CT_MODE_COUNT                         0 //计数
#define EM9636_CT_MODE_HFREQ                         1 //测高频
#define EM9636_CT_MODE_LFREQ                         3 //测低频

//IO方向
#define EM9636_IO_IN                                 0 //输入
#define EM9636_IO_OUT                                1 //输出

//IO是否进FIFO
#define EM9636_IOINFIFO_NO                           0 //不进FIFO
#define EM9636_IOINFIFO_YES                          1 //进FIFO

#define EM9636_TIMOUT_MS                             1000 //超时毫秒数

extern "C"
{

I32 _stdcall EM9636_DeviceCreate();
//函数功能：创建设备
//入口参数：
//      无
//返回值：-1，创建设备失败
//        其它值为设备句柄，在以后的设备相关操作中均要使用其返回值

void _stdcall EM9636_DeviceClose( I32 hDevice );
//函数功能：关闭设备，同时释放设备所占用资源
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//返回值：无

I32 _stdcall EM9636_CmdConnect( I32 hDevice, char* strIP, I32 ipBC, I32 cmdPort, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：连接命令端口
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//             strIP：设备IP
//              ipBC：strIP的长度，此参数为0时表示strIP是以0为结束的字符串。
//           cmdPort：命令端口号。
//         timeOutMS：超时毫秒数。
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_DataConnect( I32 hDevice, I32 dataPort, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：连接数据端口，调用此函数之前必须先调用EM9636_CmdConnect
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//          dataPort：数据端口号。
//返回值：0表示成功，<0表示失败

void _stdcall EM9636_CmdClose( I32 hDevice, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：关闭命令端口
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//返回值：0表示成功，<0表示失败

void _stdcall EM9636_DataClose( I32 hDevice, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：关闭数据端口
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_AdSetChRange( I32 hDevice, I32 beginNo, I32 endNo, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置AD通道范围，只有设置范围内的通道采集数据
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//           beginNo：起始通道号，1~32
//             endNo：终止通道号
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_AdSetEndMode( I32 hDevice, I32 endMode, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置AD单双端方式，注意要与设备跳线一致
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//           endMode：单双端方式，0表示单端，1表示差分
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_AdSetRange( I32 hDevice, I32 rangeInx, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置AD采集范围，注意要与设备跳线一致
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//          rangeInx：采集范围
//                    0，±10V
//                    1，±5V
//                    2，0~10V
//                    3，0~5V
//                    4，0~20mA
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_AdSetGain( I32 hDevice, I32 gainInx, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置AD增益
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//           gainInx：增益系数
//                    0，没有增益
//                    1，2倍增益
//                    2，5倍增益
//                    3，10倍增益
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_AdReadOnceCode( I32 hDevice, I32 beginChNo, I32 endChNo, U16* adCode, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：读取一次AD数据值
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//         beginChNo：起始通道号，1~endChNo
//           endChNo：终止通道号，beginChNo~32
//出口参数：
//            adCode：AD数据原码值数组，数组所包含元素数目为（endChNo - beginChNo + 1），需要用户分配空间
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_AdGetValue( I32 hDevice, U16* adCode, I32 adCodeCount, double* adValue );
//函数功能：将AD原码值转换成物理值
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//            adCode：AD原码值数组，数组所包含元素数目为codeCount
//       adCodeCount：原码值数组所包含元素数目
//出口参数：
//           adValue：AD物理值转换结果，数组大小为adCodeCount，需要用户分配空间
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_TriSetSrc( I32 hDevice, I32 triSrc, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置高速采集触发源
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//            triSrc：触发源
//                    0,内触发
//                    1,外触发
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_TriSetMode( I32 hDevice, I32 triMode, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置高速采集触发方式
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//           triMode：触发方式
//                    0,上升沿触发
//                    1,高电平触发
//                    2,下降沿触发
//                    3,低电平触发
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_HcSetChFreq( I32 hDevice,  F64 chFreq, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置通道切换频率
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//            chFreq：通道切换频率，最高250000(250K)
//出口参数：
//                无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_HcSetGroupFreq( I32 hDevice,  F64 groupFreq, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置组频率
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//         groupFreq：组频率，需要小于 通道切换频率/通道号
//出口参数：
//                无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_HcStart( I32 hDevice, I32 isPSync, I32 clkSrc, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：启动硬件控制采集
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//           isPSync：是否伪同步，0非伪同步，1伪同步
//            clkSrc：时钟源，0内时钟，1外时钟
//出口参数：
//                无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_HcStop( I32 hDevice, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：停止硬件控制采集
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//出口参数：
//                无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636M_HcStart( I32 hDevice, I32 isPSync, I32 clkSrc, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：启动硬件控制采集，因为EM9636M下位机缓冲区比较小，需要及时读取数据，调用此函数后dll中将建立线程自动读取数据
//          然后存储到缓冲区中。用户可以调用EM9636M_HcSFifoRead函数从缓冲区中读取数据
//          必须和EM9636M_HcStop配合使用
//          注意：此函数调用后请不要调用EM9636M_HcSFifoRead
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//           isPSync：是否伪同步，0非伪同步，1伪同步
//            clkSrc：时钟源，0内时钟，1外时钟
//出口参数：
//                无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636M_HcStop( I32 hDevice, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：停止硬件控制采集，必须和EM9636M_HcStart配合使用
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//出口参数：
//                无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636M_HcSFifoCanReadCount( I32 hDevice, I32* canReadCount );
//函数功能：得到上位机软件缓冲区数据个数
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//         canReadCount：可读数据个数，每个数据占2个字节。
//出口参数：
//                无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636M_HcSFifoRead( I32 hDevice, I32 dataCount, U16* dataBuffer, I32* realReadCount );
//函数功能：在硬件控制采集启动后，使用此函数读回上位机缓冲区中的采集结果
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//         dataCount：数据个数，每个数据占2个字节。
//出口参数：
//        dataBuffer：数据缓冲区数组，需要用户分配，元素个数至少为dataCount
//     realReadCount：实际读回数据个数，需要用户分配
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_HcReadData( I32 hDevice, I32 dataCount, U16* dataBuffer, I32* realReadCount, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：在硬件控制采集启动后，使用此函数读回采集结果
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//         dataCount：数据个数，每个数据占2个字节。
//出口参数：
//        dataBuffer：数据缓冲区数组，需要用户分配，元素个数至少为dataCount
//     realReadCount：实际读回数据个数，需要用户分配
//返回值：0表示成功，<0表示失败
I32 _stdcall EM9636M_HcFifoStatus( I32 hDevice, I32* hFifoStatus, I32* sFifoStatus, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：在硬件控制采集启动后，使用此函数判断下位机
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//出口参数：
//       hFifoStatus：下位机硬件缓冲区溢出
//       sFifoStatus：下位机软件缓冲区溢出
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_AdGetCode( I32 hDevice, U16* usCode, I32 codeCount, U16* adCode, I32* adCodeCount );
//函数功能：将AD原码从原码值中提取出来，当高速缓冲区中有IO值存在时，需要调用此函数提取AD原码
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//            usCode：原码值数组，数组所包含元素数目为codeCount，由EM9636_HcReadData返回
//         codeCount：原码值数组所包含元素数目，需要是高速缓冲区中所有通道数目的整数倍。
//出口参数：
//            adCode：AD原码值数组，数组大小为adCodeCount，需要用户分配空间
//       adCodeCount：AD原码值数量。
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_IoGetCode( I32 hDevice, U16* usCode, I32 codeCount, U16* ioCode, I32* ioCodeCount );
//函数功能：将AD原码从原码值中提取出来，当高速缓冲区中有IO值存在时，需要调用此函数提取AD原码
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//            usCode：原码值数组，数组所包含元素数目为codeCount，由EM9636_HcReadData返回
//         codeCount：原码值数组所包含元素数目，需要是高速缓冲区中所有通道数目的整数倍。
//出口参数：
//            ioCode：AD原码值数组，数组大小为adCodeCount，需要用户分配空间
//       ioCodeCount：AD原码值数量。
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_DaSetOutMode( I32 hDevice, I32 chNo, I32 codeOrVal, long rangeInx, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：DA输出方式
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//              chNo：通道号，1~4
//         codeOrVal：0表示原码值输出，1表示物理值输出
//          rangeInx：输出范围
//                    0，±10V
//                    1，±5V
//                    2，0~10V
//                    3，0~5V
//                    4，0~20mA
//出口参数：
//                无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_DaSet( I32 hDevice, I32 chNo, I16 daValue, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置DA输出值
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//              chNo：通道号，1~4
//           daValue：根据EM9636_DaSetOutMode设置，表示原码值或者毫伏或者毫安值
//出口参数：
//                无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_DaAutoSet( I32 hDevice, I16 daValue[4], I32 stepCnt, I32 stepTime, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置DA自动输出数据，此命令为定制，一般用户用不到
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//           daValue：具有四个元素的数组，分别对应1~4通道的微安值
//           stepCnt：步数，32~1000
//          stepTime：每步间隔，1~100ms
//出口参数：
//                无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_DaAutoGet( I32 hDevice, I16 daValue[4], I32* stepCnt, I32* stepTime, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：得到当前DA自动输出值
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//出口参数：
//           daValue：具有四个元素的数组，分别对应1~4通道的微安值
//           stepCnt：步数，32~1000
//          stepTime：每步间隔，1~100ms
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_IoSetDir( I32 hDevice, I8 dir[4], I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置开关量方向
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//               dir：4字节数组，dir[0]对应IO1~IO8，dir[1]对应IO9~IO16
//出口参数：
//                  无
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_IoGetAll( I32 hDevice, I8 iStatus[32], I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：得到所有通道开关量值
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//出口参数：
//           iStatus：32字节数组
//                    iStatus[0]~iStatus[15]对应IO1~IO16
//                    iStatus[16]~iStatus[23]对应DI1~DI8
//                    iStatus[24]~iStatus[31]对应DO1~DO8
//
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_IoSetAll( I32 hDevice, I8 oStatus[32], I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置所有通道开关量值，如果对应开关量方向设置为输入，则对应开关量的设置无效
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//           oStatus：32字节数组
//                    oStatus[0]~oStatus[15]对应IO1~IO16
//                    oStatus[16]~oStatus[23]对应DI1~DI8
//                    oStatus[24]~oStatus[31]对应DO1~DO8
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_IoInFifo( I32 hDevice, I8 isInFifo, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：得到所有通道开关量值
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//          isInFifo：0表示IO1~IO16不进入FIFO
//                    1表示IO1~IO16进入FIFO
//
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_EcClear( I32 hDevice, I32 chNo, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：将指定通道的编码器清零
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//              chNo：通道号，1~2
//
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_EcReadCodeAll( I32 hDevice, I32 abCode[2], I16 zCode[2], I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：将指定通道的编码器清零
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//出口参数：
//            abCode：编码器AB值，32位有符号数组，其元素个数为2，需要用户分配空间。
//             zCode：编码器过零值，16位有符号数组，其元素个数为2，需要用户分配空间。
//
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_CtSetModeAll( I32 hDevice, U16 ctMode[EM9636_MAXCTCHCNT], I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置所有路计数器的工作方式
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//            ctMode：计数器工作方式，6元素整形数组
//                    0，计数
//                    1，测高频
//                    3，测低频
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_CtSetFreqBase( I32 hDevice, I32 chNo, F64 freqBase_ms, F64* real_ms, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置指定通道的计数器测频基准脉冲周期，以毫秒为单位
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//              chNo：通道号，1~6
//       freqBase_ms：测频基准周期，以毫秒为单位
//出口参数：
//           real_ms：实际测频基准，大多数情况和freqBase_ms一致
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_CtReadCodeAll( I32 hDevice, U32 ctCode[EM9636_MAXCTCHCNT], I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：读取所有路计数器的原码值
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//出口参数：
//            ctCode：计数器原码值，如果是计数方式就是计数值，如果是测频则需要计算才能转化成频率值
//                    无符号32位
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_CtCodeToValue( I32 hDevice, I32 chNo, U32 ctCode, F64* ctValue );
//函数功能：将计数器值根据原码值转换成对应的物理值，计数方式下则为计数值，测频方式下则为频率值，此函数的转换结果和EM9636_CtSetModeAll有关
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//              chNo：通道号，1~6
//            ctCode：计数器原码值，由EM9636_CtReadCodeAll函数返回
//出口参数：
//           ctValue：计数方式下为计数值，测频方式下为测频值
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_CtClear( I32 hDevice, I32 chNo, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：指定通道计数器清零	
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//              chNo：通道号，1~6
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_CmdEnableWTD( I32 hDevice, U16 overTimeS, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：使能通讯看门狗,当下位机在overTimeS秒内没有接收到任何命令将会视为通讯中断，此时上位机需要重新调用EM9636_CmdConnect函数。
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//         overTimeS：超时秒数
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_PwmSetPulse( I32 hDevice, I32 chNo, F64 freq, F64 duty, F64* realFreq, F64* realDuty, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设置PWM频率和占空比。
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//              chNo：通道号1~3
//              freq：频率，最小为250Hz
//              duty：占空比，0~1
//出口参数：
//          realFreq：实际频率，通常和freq一致
//          realDuty：实际占空比，通常和duty一致
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_PwmSet1Pulse32bit( I32 hDevice, I32 chNo, F64 freq, F64 duty, F64* realFreq, F64* realDuty, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：只用定制成1路32位PWM产品才可以使用，设置PWM频率和占空比。
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//              chNo：通道号只能为1
//              freq：频率，最小为0.01Hz
//              duty：占空比，0~1
//出口参数：
//          realFreq：实际频率，通常和freq一致
//          realDuty：实际占空比，通常和duty一致
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_PwmStartOrStopAll( I32 hDevice, I8 startOrStop, I32 timeOutMS = EM9636_TIMOUT_MS  );
//函数功能：使能或禁止PWM输出，目前只能全部使能和全部禁止
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//       startOrStop：0表示禁止所有PWM输出，1表示使能所有PWM输出
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636M_PwmStartAll( I32 hDevice, I8 startOrStop[EM9636_MAXPWMCHCNT], I8 is90[EM9636_MAXPWMCHCNT], I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设定所有通道的PWM输出开始或者停止,本函数只支持EM9636M以及部分EM9636定制产品。
//注意：在使用PWM功能前，应该调用EM9636_IoSetDir函数将IO1~IO8的设成输出
//入口参数：
//                hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//            startOrStop：启动设置数组，数组元素0~2对应PWM1~PWM3，以PWM1为例：
//                         startOrStop[0]=0，停止输出
//                         startOrStop[0]=1，启动输出
//                   is90：相位设置数组，数组元素0~2对应PWM1~PWM3，以PWM1为例：
//                         is90[0]=0，输出滞后90度
//                         is90[0]=1，输出不滞后90度
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636M_PwmSetCount( I32 hDevice, I32 chNo, U32 pwmCount, I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：设定输出脉冲个数,此函数只有定制产品支持
//入口参数：
//                hDevice：设备句柄
//                   chNo：通道号，1~3
//               setCount：脉冲个数，如果设为，则表示连续输出
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636M_PwmIsOver( I32 hDevice, I8 isOver[EM9636_MAXPWMCHCNT], I32 timeOutMS = EM9636_TIMOUT_MS );
//函数功能：在制定脉冲数出个数的情况下，判断PWM输出是否完成,此函数只有EM9636M和部分定制EM9636支持
//入口参数：
//                hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//                 isOver：是否完成，数组元素0~2对应PWM1~3，以PWM1为例：
//                           isOver[0]=0，输出没有完成
//                           isOver[0]=1，输出已经完成
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_ReadW( I32 hDevice, U32 regAddress, U32* regData, I32 timeOutMS = EM9636_TIMOUT_MS  );
//函数功能：读取下位机寄存器，本函数定制使用，普通用户不需调用
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//        regAddress：寄存器地址
//           regData：寄存器内容，低十六位有效
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_WriteW( I32 hDevice, U32 regAddress, U32 regData, I32 timeOutMS = EM9636_TIMOUT_MS  );
//函数功能：读取下位机寄存器，本函数定制使用，普通用户不需调用
//入口参数：
//           hDevice：设备句柄，EM9636_DeviceCreate函数返回值
//        regAddress：寄存器地址
//           regData：寄存器内容，低十六位有效
//返回值：0表示成功，<0表示失败

I32 _stdcall EM9636_OlFileOpen( I8* filePathName );
//函数功能：打开数据文件
//入口参数：
//      filePathName：文件路径
//返回值：-1,打开文件失败
//        其它值为文件句柄

I32 _stdcall EM9636_OlGetDataBytesCount( I32 fileHandle );
//函数功能：从离线数据文件中得到总数据量，以字节位单位
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//返回值：>0,总数据量
//        <0,表示读取失败

I32 _stdcall EM9636_OlGetAdEnCh( I32 fileHandle, I8 enCh[EM9636_MAXADCHCNT] );
//函数功能：从离线数据文件中得到使能通道数，此参数用于慢速采集
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//            enCh：返回AD的使能通道，长度为32的字节数组
//返回值：>0,返回使能通道数量
//        <0,表示读取失败

I32 _stdcall EM9636_OlGetAdChRange( I32 fileHandle, I32* beginChNo, I32* endChNo );
//函数功能：从离线数据文件中得到AD通道范围
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//       beginChNo：起始通道
//         endChNo：停止通道
//返回值：>0,返回使能通道数量
//        <0,表示读取失败

I32 _stdcall EM9636_OlGetGroupBytesCount( I32 fileHandle );
//函数功能：从离线数据文件中得到高速数据每组字节数，也就是每次采样所获得的数据字节数
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//返回值：>0,每组字节数
//        <0,表示读取失败

I32 _stdcall EM9636_OlGetGroupFreq( I32 fileHandle, F64* groupFreq );
//函数功能：从离线数据文件中得到组频率值
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//       groupFreq：以Hz为单位的采集频率
//返回值：=0,表示成功

I32 _stdcall EM9636_OlGetOriginalCode( I32 fileHandle, I32 readPos, U32 bytesCount, U8* originalCode, U32* realBC );
//函数功能：从离线数据文件中获取原始数据
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//         readPos：读取位置，第一个采集通道第一个采集点的读取位置为0，如果为-1表示从当前位置读取
//      bytesCount：要读取的字节数。
//出口参数：
//    originalCode：数据缓冲区，需要用户分配，其大小为bytesCount
//          realBC：实际读取的字节数
//返回值：>0,返回文件当前指向的位置，可以用于确定下一次读取的位置
//        <0,表示读取失败

I32 _stdcall EM9636_OlDirOpen( I8* path );
//函数功能：打开数据文件目录，此函数将符合格式的目录打开，准备按照存储日期顺序分析文件
//入口参数：
//            path：目录的路径，此目录内部结构必须和离线文件存储盘的结构一致。
//                  离线文件存储盘目录结构：根目录是日期文件夹，每个日期文件夹内是数据文件。
//返回值：-1,打开文件失败
//        其它值为文件句柄

I32 _stdcall EM9636_OlGetAdChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, U16* adChCode, U32* adCodeCount );
//函数功能：从高速采集原始数据中获取AD原码值
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//           chInx：通道索引，0~实际使能通道数-1，这里的通道索引是指离线文件使能通道的序号，比如使能了AD5和AD6两个通道，则chInx=0时表示要取得AD5的值，chInx=1时表示要取得AD6的值
//      bytesCount：originalCode所包含数据的字节数。
//    originalCode：原始码缓冲区
//出口参数：
//        adChCode：指定通道的数据接收数组，需要用户分配空间，类型为16位无符号整型，数组大小为bytesCount/每组字节数，每组字节数可以由EM9636_OlGetGroupBytesCount函数得到，用户也可以分配bytesCount个数，然后再根据adCodeCount来截取数组。
//     adCodeCount：adChCode返回的有效数据个数，=0则表示不返回。
//返回值：<0,表示操作失败

I32 _stdcall EM9636_OlAdGetValue( I32 fileHandle, U16* usCode, I32 codeCount, double* adValue );
//函数功能：将离线AD数据转换成物理值
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//          usCode：原码值缓冲区，应该是EM9636_OlGetAdChCode返回的值
//       codeCount：AD数据个数，应该是EM9636_OlGetAdChCode中的adCodeCount返回值
//出口参数：
//         adValue：物理值缓冲区，其大小不能小于codeCount
//返回值：<0,表示操作失败

I32 _stdcall EM9636_OlAdGetRange( I32 fileHandle, I8* rangeInx );
//函数功能：从离线数据文件中得到采集范围
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//       rangeInx：采集范围索引
//返回值：=0,表示成功

I32 _stdcall EM9636_OlGetChFreq( I32 fileHandle, F64* chFreq );
//函数功能：从离线数据文件中得到通道切换频率值
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//       chFreq：以Hz为单位的采集频率
//返回值：=0,表示成功

I32 _stdcall EM9636_OlGetIsPSync( I32 fileHandle, I32* isPSync );
//函数功能：从离线数据文件中得到是否为伪同步采集
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//         isPSync：返回0表示不是伪同步，1为伪同步
//返回值：=0,表示成功

I32 _stdcall EM9636_OlGetCtEnCh( I32 fileHandle, I8* enCh );
//函数功能：从离线数据文件中得到计数器的使能通道，此参数用于慢速采集
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//            enCh：6元素数组，返回1表示此通道存储
//返回值：>=0,表示成功

I32 _stdcall EM9636_OlGetCtMode( I32 fileHandle, I8* ctMode );
//函数功能：从离线数据文件中得到计数器的工作方式，此参数用于慢速采集
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//          ctMode：6元素数组
//返回值：>=0,表示成功

I32 _stdcall EM9636_OlGetCtGate( I32 fileHandle, I32* ctGate );
//函数功能：从离线数据文件中得到计数器的工作方式，此参数用于慢速采集
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//          ctGate：6元素数组
//返回值：>=0,表示成功

I32 _stdcall EM9636_OlGetEcEnCh( I32 fileHandle, I8* enCh );
//函数功能：从离线数据文件中得到编码器的使能通道，此参数用于慢速采集
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//            enCh：2元素数组，返回1表示此通道存储
//返回值：>=0,表示成功
I32 _stdcall EM9636_OlGetIoEnCh( I32 fileHandle, I8* enCh );
//函数功能：从离线数据文件中得到的开关量使能组，此参数用于慢速采集
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//            enCh：4元素数组，返回1表示此组IO存储
//返回值：>=0,表示成功

I32 _stdcall EM9636_OlGetIoInFifo( I32 fileHandle, I8* ioInFifo );
//函数功能：从离线数据文件中得到的开关量是否进FIFO信息，此参数用于高速采集
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//出口参数：
//        ioInFifo：字节指针，返回1表示IO1～IO16进入FIFO，注意只有在StartMode不为0的时候才有效。
//返回值：>=0,表示成功

I32 _stdcall EM9636_OlGetIoInFifoCode( I32 fileHandle, U32 bytesCount, U8* originalCode, U16* ioCode, U32* ioCodeCount );
//函数功能：从高速采集原始数据中获取IO1~IO16值
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//      bytesCount：originalCode所包含数据的字节数。
//    originalCode：原始码缓冲区
//出口参数：
//          ioCode：指定通道的数据接收数组，需要用户分配空间，类型为16位无符号整型，数组大小为bytesCount/每组字节数，每组字节数可以由EM9636_OlGetGroupBytesCount函数得到，用户也可以分配bytesCount个数，然后再根据adCodeCount来截取数组。
//     ioCodeCount：ioCode返回的有效数据个数，=0则表示不返回。
//返回值：<0,表示操作失败

I32 _stdcall EM9636_OlGetLsGroupBytesCount( I32 fileHandle );
//函数功能：从离线数据文件中得到慢速数据每组字节数，也就是每次采样所获得的数据字节数
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//返回值：>0,每组字节数
//        <0,表示读取失败

I32 _stdcall EM9636_OlGetLsAdChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, U16* adCode, U32* adCodeCount );
//函数功能：从慢速采集原始数据中获取AD原码值
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//           chInx：通道索引，0~实际使能通道数-1，这里的通道索引是指离线文件使能通道的序号，比如使能了AD5和AD6两个通道，则chInx=0时表示要取得AD5的值，chInx=1时表示要取得AD6的值
//      bytesCount：originalCode所包含数据的字节数。
//    originalCode：原始码缓冲区
//出口参数：
//        adChCode：指定通道的数据接收数组，需要用户分配空间，类型为16位无符号整型，数组大小为bytesCount/每组字节数，每组字节数可以由EM9636_OlGetLsGroupBytesCount函数得到，用户也可以分配bytesCount个数，然后再根据adCodeCount来截取数组。
//     adCodeCount：adChCode返回的有效数据个数，=0则表示不返回。
//返回值：<0,表示操作失败

I32 _stdcall EM9636_OlGetLsIoGroupCode( I32 fileHandle, I32 groupInx, U32 bytesCount, U8* originalCode, U8* ioCode, U32* ioCodeCount );
//函数功能：从慢速采集原始数据中获取IO原码值
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//        groupInx：组索引，每8个IO通道为一组。
//      bytesCount：originalCode所包含数据的字节数。
//    originalCode：原始码缓冲区
//出口参数：
//          ioCode：指定组的数据接收数组，需要用户分配空间，类型为8位无符号整型，数组大小为bytesCount/每组字节数，每组字节数可以由EM9636_OlGetLsGroupBytesCount函数得到，用户也可以分配bytesCount个数，然后再根据ioCodeCount来截取数组。
//     ioCodeCount：adChCode返回的有效数据个数，=0则表示不返回。
//返回值：<0,表示操作失败

I32 _stdcall EM9636_OlGetLsCtChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, U32* ctCode, U32* ctCodeCount );
//函数功能：从慢速采集原始数据中获取CT原码值
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//           chInx：通道索引，0~实际使能通道数-1，这里的通道索引是指离线文件使能通道的序号，比如使能了CT5和CT6两个通道，则chInx=0时表示要取得CT5的值，chInx=1时表示要取得CT6的值
//      bytesCount：originalCode所包含数据的字节数。
//    originalCode：原始码缓冲区
//出口参数：
//          ctCode：指定通道的数据接收数组，需要用户分配空间，类型为32位无符号整型，数组大小为bytesCount/每组字节数，每组字节数可以由EM9636_OlGetLsGroupBytesCount函数得到，用户也可以分配bytesCount个数，然后再根据ctCodeCount来截取数组。
//     ctCodeCount：adChCode返回的有效数据个数，=0则表示不返回。
//返回值：<0,表示操作失败

I32 _stdcall EM9636_OlGetLsEcChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, I32* abCode, I32* zCode, U32* ecCodeCount );
//函数功能：从慢速采集原始数据中获取编码器原码值
//入口参数：
//      fileHandle：文件句柄，EM9636_OlFileOpen的返回值
//           chInx：通道索引，0~实际使能通道数-1，这里的通道索引是指离线文件使能通道的序号，比如使能了EC2一个通道，则chInx=0时表示要取得EC2的值
//      bytesCount：originalCode所包含数据的字节数。
//    originalCode：原始码缓冲区
//出口参数：
//          abCode：指定通道的AB数据接收数组，需要用户分配空间，类型为32位有符号整型，数组大小为bytesCount/每组字节数，每组字节数可以由EM9636_OlGetLsGroupBytesCount函数得到，用户也可以分配bytesCount个数，然后再根据ecCodeCount来截取数组。
//           zCode：指定通道的Z数据接收数组，需要用户分配空间，类型为32位有符号整型，数组大小为bytesCount/每组字节数，每组字节数可以由EM9636_OlGetLsGroupBytesCount函数得到，用户也可以分配bytesCount个数，然后再根据ecCodeCount来截取数组。
//     ecCodeCount：adChCode返回的有效数据个数，=0则表示不返回。
//返回值：<0,表示操作失败

};

#endif