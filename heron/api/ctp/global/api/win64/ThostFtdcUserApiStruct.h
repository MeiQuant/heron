/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file ThostFtdcUserApiStruct.h
///@brief 定义了客户端接口使用的业务数据结构
///@history 
///20060106	赵鸿昊		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(CTPGLOBAL_THOST_FTDCSTRUCT_H)
#define CTPGLOBAL_THOST_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ThostFtdcUserApiDataType.h"
namespace CTPGlobal{
///信息分发
struct CThostFtdcDisseminationField
{
	///序列系列号
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///序列号
	TThostFtdcSequenceNoType	SequenceNo;
};

///用户登录请求
struct CThostFtdcReqUserLoginField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///密码
	TThostFtdcPasswordType	Password;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
	///动态密码
	TThostFtdcPasswordType	OneTimePassword;
	///终端IP地址
	TThostFtdcIPAddressType	ClientIPAddress;
	///语言类型
	TThostFtdcLanguageTypeType	Lang;
	///登录备注
	TThostFtdcRemarkType	Remark;
};

///用户登录应答
struct CThostFtdcRspUserLoginField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///登录成功时间
	TThostFtdcTimeType	LoginTime;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///交易系统名称
	TThostFtdcSystemNameType	SystemName;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///最大报单引用
	TThostFtdcOrderRefType	MaxOrderRef;
	///上期所时间
	TThostFtdcTimeType	SHFETime;
	///大商所时间
	TThostFtdcTimeType	DCETime;
	///郑商所时间
	TThostFtdcTimeType	CZCETime;
	///中金所时间
	TThostFtdcTimeType	FFEXTime;
	///能源中心时间
	TThostFtdcTimeType	INETime;
	///语言类型
	TThostFtdcLanguageTypeType	Lang;
	///芝加哥商业交易所
	TThostFtdcTimeType	CMETime;
};

///用户登出请求
struct CThostFtdcUserLogoutField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///强制交易员退出
struct CThostFtdcForceUserLogoutField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///客户端认证请求
struct CThostFtdcReqAuthenticateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///认证码
	TThostFtdcAuthCodeType	AuthCode;
};

///客户端认证响应
struct CThostFtdcRspAuthenticateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
};

///客户端认证信息
struct CThostFtdcAuthenticationInfoField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///认证信息
	TThostFtdcAuthInfoType	AuthInfo;
	///是否为认证结果
	TThostFtdcBoolType	IsResult;
	///语言类型
	TThostFtdcLanguageTypeType	Lang;
};

///响应信息
struct CThostFtdcRspInfoField
{
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///交易所
struct CThostFtdcExchangeField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所名称
	TThostFtdcExchangeNameType	ExchangeName;
	///交易所属性
	TThostFtdcExchangePropertyType	ExchangeProperty;
};

///产品
struct CThostFtdcProductField
{
	///品种代码
	TThostFtdcProductIDType	ProductID;
	///产品名称
	TThostFtdcProductNameType	ProductName;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///产品类型
	TThostFtdcProductClassType	ProductClass;
	///合约数量乘数
	TThostFtdcVolumeMultipleType	VolumeMultiple;
	///最小变动价位
	TThostFtdcPriceTickType	PriceTick;
	///市价单最大下单量
	TThostFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TThostFtdcVolumeType	MinMarketOrderVolume;
	///限价单最大下单量
	TThostFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TThostFtdcVolumeType	MinLimitOrderVolume;
	///持仓类型
	TThostFtdcPositionModeType	PositionMode;
	///持仓日期类型
	TThostFtdcPositionDateModeType	PositionDateMode;
	///平仓处理类型
	TThostFtdcCloseDealTypeType	CloseDealType;
	///交易币种类型
	TThostFtdcCurrencyIDType	TradeCurrencyID;
	///货币质押资金可用范围
	TThostFtdcMortgageFundUseRangeType	MortgageFundUseRange;
	///交易所产品代码
	TThostFtdcProductIDType	ExchangeProductID;
	///基础商品乘数
	TThostFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///交易所子市场代码
	TThostFtdcSubExchangeIDType	SubExchangeID;
	///交易所币种单位乘数
	TThostFtdcCurrencyUnitType	ExchangeCurrencyUnit;
};

///合约
struct CThostFtdcInstrumentField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约名称
	TThostFtdcInstrumentNameType	InstrumentName;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///品种代码
	TThostFtdcProductIDType	ProductID;
	///产品类型
	TThostFtdcProductClassType	ProductClass;
	///交割年份
	TThostFtdcYearType	DeliveryYear;
	///交割月
	TThostFtdcMonthType	DeliveryMonth;
	///市价单最大下单量
	TThostFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TThostFtdcVolumeType	MinMarketOrderVolume;
	///限价单最大下单量
	TThostFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TThostFtdcVolumeType	MinLimitOrderVolume;
	///合约数量乘数
	TThostFtdcVolumeMultipleType	VolumeMultiple;
	///最小变动价位
	TThostFtdcPriceTickType	PriceTick;
	///创建日
	TThostFtdcDateType	CreateDate;
	///上市日
	TThostFtdcDateType	OpenDate;
	///到期日
	TThostFtdcDateType	ExpireDate;
	///开始交割日
	TThostFtdcDateType	StartDelivDate;
	///结束交割日
	TThostFtdcDateType	EndDelivDate;
	///合约生命周期状态
	TThostFtdcInstLifePhaseType	InstLifePhase;
	///当前是否交易
	TThostFtdcBoolType	IsTrading;
	///持仓类型
	TThostFtdcPositionModeType	PositionMode;
	///持仓日期类型
	TThostFtdcPositionDateModeType	PositionDateMode;
	///多头保证金率
	TThostFtdcRatioType	LongMarginRatio;
	///空头保证金率
	TThostFtdcRatioType	ShortMarginRatio;
	///大额单边保证金算法
	TThostFtdcMaxMarginSideAlgorithmType	MaxMarginSideAlgorithm;
	///基础商品代码
	TThostFtdcInstrumentIDType	UnderlyingInstrID;
	///执行价
	TThostFtdcPriceType	StrikePrice;
	///期权类型
	TThostFtdcOptionsTypeType	OptionsType;
	///基础商品乘数
	TThostFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///组合类型
	TThostFtdcCombinationTypeType	CombinationType;
	///交易所子市场代码
	TThostFtdcSubExchangeIDType	SubExchangeID;
	///价格乘数
	TThostFtdcDisplayFactorType	DisplayFactor;
	///报价规则1
	TThostFtdcFractionTypeType	MainFraction;
	///报价规则2
	TThostFtdcFractionTypeType	SubFraction;
};

///经纪公司
struct CThostFtdcBrokerField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///经纪公司简称
	TThostFtdcBrokerAbbrType	BrokerAbbr;
	///经纪公司名称
	TThostFtdcBrokerNameType	BrokerName;
	///是否活跃
	TThostFtdcBoolType	IsActive;
};

///交易所交易员
struct CThostFtdcTraderField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///密码
	TThostFtdcPasswordType	Password;
	///使用的流类型
	TThostFtdcSubjectIDType	SubjectID;
	///IP限制范围
	TThostFtdcIPAddressType	IpRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///投资者
struct CThostFtdcInvestorField
{
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者分组代码
	TThostFtdcInvestorIDType	InvestorGroupID;
	///投资者名称
	TThostFtdcPartyNameType	InvestorName;
	///证件类型
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///是否活跃
	TThostFtdcBoolType	IsActive;
	///联系电话
	TThostFtdcTelephoneType	Telephone;
	///通讯地址
	TThostFtdcAddressType	Address;
	///开户日期
	TThostFtdcDateType	OpenDate;
	///手机
	TThostFtdcMobileType	Mobile;
	///手续费率模板代码
	TThostFtdcInvestorIDType	CommModelID;
	///保证金率模板代码
	TThostFtdcInvestorIDType	MarginModelID;
};

///交易编码
struct CThostFtdcTradingCodeField
{
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///是否活跃
	TThostFtdcBoolType	IsActive;
	///交易编码类型
	TThostFtdcClientIDModeType	ClientIDMode;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///会员编码和经纪公司编码对照表
struct CThostFtdcPartBrokerField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///是否活跃
	TThostFtdcBoolType	IsActive;
	///经纪公司类型
	TThostFtdcPartTypeType	ParticipantType;
};

///管理用户
struct CThostFtdcSuperUserField
{
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户名称
	TThostFtdcUserNameType	UserName;
	///密码
	TThostFtdcPasswordType	Password;
	///是否活跃
	TThostFtdcBoolType	IsActive;
};

///管理用户功能权限
struct CThostFtdcSuperUserFunctionField
{
	///用户代码
	TThostFtdcUserIDType	UserID;
	///功能代码
	TThostFtdcFunctionCodeType	FunctionCode;
};

///投资者组
struct CThostFtdcInvestorGroupField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者分组代码
	TThostFtdcInvestorIDType	InvestorGroupID;
	///投资者分组名称
	TThostFtdcInvestorGroupNameType	InvestorGroupName;
};

///资金账户
struct CThostFtdcTradingAccountField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///上次质押金额
	TThostFtdcMoneyType	PreMortgage;
	///上次信用额度
	TThostFtdcMoneyType	PreCredit;
	///上次存款额
	TThostFtdcMoneyType	PreDeposit;
	///上次结算准备金
	TThostFtdcMoneyType	PreBalance;
	///上次占用的保证金
	TThostFtdcMoneyType	PreMargin;
	///利息基数
	TThostFtdcMoneyType	InterestBase;
	///利息收入
	TThostFtdcMoneyType	Interest;
	///入金金额
	TThostFtdcMoneyType	Deposit;
	///出金金额
	TThostFtdcMoneyType	Withdraw;
	///冻结的保证金
	TThostFtdcMoneyType	FrozenMargin;
	///冻结的资金
	TThostFtdcMoneyType	FrozenCash;
	///冻结的手续费
	TThostFtdcMoneyType	FrozenCommission;
	///当前保证金总额
	TThostFtdcMoneyType	CurrMargin;
	///资金差额
	TThostFtdcMoneyType	CashIn;
	///手续费
	TThostFtdcMoneyType	Commission;
	///平仓盈亏
	TThostFtdcMoneyType	CloseProfit;
	///持仓盈亏
	TThostFtdcMoneyType	PositionProfit;
	///期货结算准备金
	TThostFtdcMoneyType	Balance;
	///可用资金
	TThostFtdcMoneyType	Available;
	///可取资金
	TThostFtdcMoneyType	WithdrawQuota;
	///基本准备金
	TThostFtdcMoneyType	Reserve;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///信用额度
	TThostFtdcMoneyType	Credit;
	///质押金额
	TThostFtdcMoneyType	Mortgage;
	///交易所保证金
	TThostFtdcMoneyType	ExchangeMargin;
	///投资者交割保证金
	TThostFtdcMoneyType	DeliveryMargin;
	///交易所交割保证金
	TThostFtdcMoneyType	ExchangeDeliveryMargin;
	///保底期货结算准备金
	TThostFtdcMoneyType	ReserveBalance;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///上次货币质入金额
	TThostFtdcMoneyType	PreFundMortgageIn;
	///上次货币质出金额
	TThostFtdcMoneyType	PreFundMortgageOut;
	///货币质入金额
	TThostFtdcMoneyType	FundMortgageIn;
	///货币质出金额
	TThostFtdcMoneyType	FundMortgageOut;
	///货币质押余额
	TThostFtdcMoneyType	FundMortgageAvailable;
	///可质押货币金额
	TThostFtdcMoneyType	MortgageableFund;
	///特殊产品占用保证金
	TThostFtdcMoneyType	SpecProductMargin;
	///特殊产品冻结保证金
	TThostFtdcMoneyType	SpecProductFrozenMargin;
	///特殊产品手续费
	TThostFtdcMoneyType	SpecProductCommission;
	///特殊产品冻结手续费
	TThostFtdcMoneyType	SpecProductFrozenCommission;
	///特殊产品持仓盈亏
	TThostFtdcMoneyType	SpecProductPositionProfit;
	///特殊产品平仓盈亏
	TThostFtdcMoneyType	SpecProductCloseProfit;
	///根据持仓盈亏算法计算的特殊产品持仓盈亏
	TThostFtdcMoneyType	SpecProductPositionProfitByAlg;
	///特殊产品交易所保证金
	TThostFtdcMoneyType	SpecProductExchangeMargin;
	///币种名称
	TThostFtdcCurrencyNameType	CurrencyName;
	///维持保证金
	TThostFtdcMoneyType	MaintenMargin;
	///交易所维持保证金
	TThostFtdcMoneyType	ExchangeMaintenMargin;
};

///投资者持仓
struct CThostFtdcInvestorPositionField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///持仓多空方向
	TThostFtdcPosiDirectionType	PosiDirection;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///持仓日期
	TThostFtdcPositionDateType	PositionDate;
	///上日持仓
	TThostFtdcVolumeType	YdPosition;
	///当前持仓
	TThostFtdcVolumeType	Position;
	///多头冻结
	TThostFtdcVolumeType	LongFrozen;
	///空头冻结
	TThostFtdcVolumeType	ShortFrozen;
	///多头报单冻结金额
	TThostFtdcMoneyType	LongFrozenAmount;
	///空头报单冻结金额
	TThostFtdcMoneyType	ShortFrozenAmount;
	///开仓量
	TThostFtdcVolumeType	OpenVolume;
	///平仓量
	TThostFtdcVolumeType	CloseVolume;
	///开仓金额
	TThostFtdcMoneyType	OpenAmount;
	///平仓金额
	TThostFtdcMoneyType	CloseAmount;
	///持仓成本
	TThostFtdcMoneyType	PositionCost;
	///上次占用的保证金
	TThostFtdcMoneyType	PreMargin;
	///占用的保证金
	TThostFtdcMoneyType	UseMargin;
	///冻结的保证金
	TThostFtdcMoneyType	FrozenMargin;
	///冻结的资金
	TThostFtdcMoneyType	FrozenCash;
	///冻结的手续费
	TThostFtdcMoneyType	FrozenCommission;
	///资金差额
	TThostFtdcMoneyType	CashIn;
	///手续费
	TThostFtdcMoneyType	Commission;
	///平仓盈亏
	TThostFtdcMoneyType	CloseProfit;
	///持仓盈亏
	TThostFtdcMoneyType	PositionProfit;
	///上次结算价
	TThostFtdcPriceType	PreSettlementPrice;
	///本次结算价
	TThostFtdcPriceType	SettlementPrice;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///开仓成本
	TThostFtdcMoneyType	OpenCost;
	///交易所保证金
	TThostFtdcMoneyType	ExchangeMargin;
	///组合成交形成的持仓
	TThostFtdcVolumeType	CombPosition;
	///组合多头冻结
	TThostFtdcVolumeType	CombLongFrozen;
	///组合空头冻结
	TThostFtdcVolumeType	CombShortFrozen;
	///逐日盯市平仓盈亏
	TThostFtdcMoneyType	CloseProfitByDate;
	///逐笔对冲平仓盈亏
	TThostFtdcMoneyType	CloseProfitByTrade;
	///今日持仓
	TThostFtdcVolumeType	TodayPosition;
	///保证金率
	TThostFtdcRatioType	MarginRateByMoney;
	///保证金率(按手数)
	TThostFtdcRatioType	MarginRateByVolume;
	///执行冻结
	TThostFtdcVolumeType	StrikeFrozen;
	///执行冻结金额
	TThostFtdcMoneyType	StrikeFrozenAmount;
	///放弃执行冻结
	TThostFtdcVolumeType	AbandonFrozen;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///维持保证金
	TThostFtdcMoneyType	MaintenMargin;
	///交易所维持保证金
	TThostFtdcMoneyType	ExchMaintenMargin;
};

///合约保证金率
struct CThostFtdcInstrumentMarginRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///多头保证金率
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///多头保证金费
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///空头保证金率
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///空头保证金费
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///是否相对交易所收取
	TThostFtdcBoolType	IsRelative;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///多头维持保证金率
	TThostFtdcRatioType	LMaintenMarginRatioByMoney;
	///多头维持保证金费
	TThostFtdcMoneyType	LMaintenMarginRatioByVolume;
	///空头维持保证金率
	TThostFtdcRatioType	SMaintenMarginRatioByMoney;
	///空头维持保证金费
	TThostFtdcMoneyType	SMaintenMarginRatioByVolume;
};

///合约手续费率
struct CThostFtdcInstrumentCommissionRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///开仓手续费率
	TThostFtdcRatioType	OpenRatioByMoney;
	///开仓手续费
	TThostFtdcRatioType	OpenRatioByVolume;
	///平仓手续费率
	TThostFtdcRatioType	CloseRatioByMoney;
	///平仓手续费
	TThostFtdcRatioType	CloseRatioByVolume;
	///平今手续费率
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///平今手续费
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///深度行情
struct CThostFtdcDepthMarketDataField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///最新价
	TThostFtdcPriceType	LastPrice;
	///上次结算价
	TThostFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TThostFtdcPriceType	PreClosePrice;
	///昨持仓量
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///今开盘
	TThostFtdcPriceType	OpenPrice;
	///最高价
	TThostFtdcPriceType	HighestPrice;
	///最低价
	TThostFtdcPriceType	LowestPrice;
	///数量
	TThostFtdcVolumeType	Volume;
	///成交金额
	TThostFtdcMoneyType	Turnover;
	///持仓量
	TThostFtdcLargeVolumeType	OpenInterest;
	///今收盘
	TThostFtdcPriceType	ClosePrice;
	///本次结算价
	TThostFtdcPriceType	SettlementPrice;
	///涨停板价
	TThostFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TThostFtdcPriceType	LowerLimitPrice;
	///昨虚实度
	TThostFtdcRatioType	PreDelta;
	///今虚实度
	TThostFtdcRatioType	CurrDelta;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TThostFtdcMillisecType	UpdateMillisec;
	///申买价一
	TThostFtdcPriceType	BidPrice1;
	///申买量一
	TThostFtdcVolumeType	BidVolume1;
	///申卖价一
	TThostFtdcPriceType	AskPrice1;
	///申卖量一
	TThostFtdcVolumeType	AskVolume1;
	///申买价二
	TThostFtdcPriceType	BidPrice2;
	///申买量二
	TThostFtdcVolumeType	BidVolume2;
	///申卖价二
	TThostFtdcPriceType	AskPrice2;
	///申卖量二
	TThostFtdcVolumeType	AskVolume2;
	///申买价三
	TThostFtdcPriceType	BidPrice3;
	///申买量三
	TThostFtdcVolumeType	BidVolume3;
	///申卖价三
	TThostFtdcPriceType	AskPrice3;
	///申卖量三
	TThostFtdcVolumeType	AskVolume3;
	///申买价四
	TThostFtdcPriceType	BidPrice4;
	///申买量四
	TThostFtdcVolumeType	BidVolume4;
	///申卖价四
	TThostFtdcPriceType	AskPrice4;
	///申卖量四
	TThostFtdcVolumeType	AskVolume4;
	///申买价五
	TThostFtdcPriceType	BidPrice5;
	///申买量五
	TThostFtdcVolumeType	BidVolume5;
	///申卖价五
	TThostFtdcPriceType	AskPrice5;
	///申卖量五
	TThostFtdcVolumeType	AskVolume5;
	///当日均价
	TThostFtdcPriceType	AveragePrice;
	///业务日期
	TThostFtdcDateType	ActionDay;
	///申买价六
	TThostFtdcPriceType	BidPrice6;
	///申买量六
	TThostFtdcVolumeType	BidVolume6;
	///申卖价六
	TThostFtdcPriceType	AskPrice6;
	///申卖量六
	TThostFtdcVolumeType	AskVolume6;
	///申买价七
	TThostFtdcPriceType	BidPrice7;
	///申买量七
	TThostFtdcVolumeType	BidVolume7;
	///申卖价七
	TThostFtdcPriceType	AskPrice7;
	///申卖量七
	TThostFtdcVolumeType	AskVolume7;
	///申买价八
	TThostFtdcPriceType	BidPrice8;
	///申买量八
	TThostFtdcVolumeType	BidVolume8;
	///申卖价八
	TThostFtdcPriceType	AskPrice8;
	///申卖量八
	TThostFtdcVolumeType	AskVolume8;
	///申买价九
	TThostFtdcPriceType	BidPrice9;
	///申买量九
	TThostFtdcVolumeType	BidVolume9;
	///申卖价九
	TThostFtdcPriceType	AskPrice9;
	///申卖量九
	TThostFtdcVolumeType	AskVolume9;
	///申买价十
	TThostFtdcPriceType	BidPrice10;
	///申买量十
	TThostFtdcVolumeType	BidVolume10;
	///申卖价十
	TThostFtdcPriceType	AskPrice10;
	///申卖量十
	TThostFtdcVolumeType	AskVolume10;
};

///投资者合约交易权限
struct CThostFtdcInstrumentTradingRightField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易权限
	TThostFtdcTradingRightType	TradingRight;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///经纪公司用户
struct CThostFtdcBrokerUserField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户名称
	TThostFtdcUserNameType	UserName;
	///用户类型
	TThostFtdcUserTypeType	UserType;
	///是否活跃
	TThostFtdcBoolType	IsActive;
	///是否使用令牌
	TThostFtdcBoolType	IsUsingOTP;
};

///经纪公司用户口令
struct CThostFtdcBrokerUserPasswordField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///密码
	TThostFtdcPasswordType	Password;
	///上次修改日期
	TThostFtdcDateType	LastChangeDate;
};

///经纪公司用户功能权限
struct CThostFtdcBrokerUserFunctionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///经纪公司功能代码
	TThostFtdcBrokerFunctionCodeType	BrokerFunctionCode;
};

///投资单元
struct CThostFtdcInvestUnitField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///投资单元名称
	TThostFtdcPartyNameType	InvestUnitName;
	///投资者分组代码
	TThostFtdcInvestorIDType	InvestorGroupID;
	///手续费率模板代码
	TThostFtdcInvestorIDType	CommModelID;
	///保证金率模板代码
	TThostFtdcInvestorIDType	MarginModelID;
	///投资单元默认资金帐号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///交易所交易员报盘机
struct CThostFtdcTraderOfferField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///密码
	TThostFtdcPasswordType	Password;
	///应用名称
	TThostFtdcAppNameType	AppName;
	///运行编号
	TThostFtdcRunIDType	RunID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///IP限制范围
	TThostFtdcIPAddressType	IpRange;
	///交易所交易员连接状态
	TThostFtdcTraderConnectStatusType	TraderConnectStatus;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///发出连接请求的日期
	TThostFtdcDateType	ConnectRequestDate;
	///发出连接请求的时间
	TThostFtdcTimeType	ConnectRequestTime;
	///上次报告日期
	TThostFtdcDateType	LastReportDate;
	///上次报告时间
	TThostFtdcTimeType	LastReportTime;
	///完成连接日期
	TThostFtdcDateType	ConnectDate;
	///完成连接时间
	TThostFtdcTimeType	ConnectTime;
	///启动日期
	TThostFtdcDateType	StartDate;
	///启动时间
	TThostFtdcTimeType	StartTime;
	///交易日
	TThostFtdcDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///经纪公司类型
	TThostFtdcPartTypeType	ParticipantType;
};

///投资者结算结果
struct CThostFtdcInvestorSettlementInfoField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///消息正文
	TThostFtdcContentType	Content;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///交易所保证金率
struct CThostFtdcExchangeMarginRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///多头保证金率
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///多头保证金费
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///空头保证金率
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///空头保证金费
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///多头维持保证金率
	TThostFtdcRatioType	LMaintenMarginRatioByMoney;
	///多头维持保证金费
	TThostFtdcMoneyType	LMaintenMarginRatioByVolume;
	///空头维持保证金率
	TThostFtdcRatioType	SMaintenMarginRatioByMoney;
	///空头维持保证金费
	TThostFtdcMoneyType	SMaintenMarginRatioByVolume;
};

///汇率
struct CThostFtdcExchangeRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///源币种
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///源币种单位数量
	TThostFtdcCurrencyUnitType	FromCurrencyUnit;
	///目标币种
	TThostFtdcCurrencyIDType	ToCurrencyID;
	///汇率
	TThostFtdcExchangeRateType	ExchangeRate;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///结算引用
struct CThostFtdcSettlementRefField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
};

///当前时间
struct CThostFtdcCurrentTimeField
{
	///当前日期
	TThostFtdcDateType	CurrDate;
	///当前时间
	TThostFtdcTimeType	CurrTime;
	///当前时间（毫秒）
	TThostFtdcMillisecType	CurrMillisec;
	///业务日期
	TThostFtdcDateType	ActionDay;
};

///通讯阶段
struct CThostFtdcCommPhaseField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///通讯时段编号
	TThostFtdcCommPhaseNoType	CommPhaseNo;
	///系统编号
	TThostFtdcSystemIDType	SystemID;
};

///登录信息
struct CThostFtdcLoginInfoField
{
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///登录日期
	TThostFtdcDateType	LoginDate;
	///登录时间
	TThostFtdcTimeType	LoginTime;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///系统名称
	TThostFtdcSystemNameType	SystemName;
	///密码
	TThostFtdcPasswordType	Password;
	///最大报单引用
	TThostFtdcOrderRefType	MaxOrderRef;
	///上期所时间
	TThostFtdcTimeType	SHFETime;
	///大商所时间
	TThostFtdcTimeType	DCETime;
	///郑商所时间
	TThostFtdcTimeType	CZCETime;
	///中金所时间
	TThostFtdcTimeType	FFEXTime;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
	///动态密码
	TThostFtdcPasswordType	OneTimePassword;
	///能源中心时间
	TThostFtdcTimeType	INETime;
	///语言类型
	TThostFtdcLanguageTypeType	Lang;
	///登录备注
	TThostFtdcRemarkType	Remark;
};

///登录信息
struct CThostFtdcLogoutAllField
{
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///系统名称
	TThostFtdcSystemNameType	SystemName;
};

///用户口令变更
struct CThostFtdcUserPasswordUpdateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///原来的口令
	TThostFtdcPasswordType	OldPassword;
	///新的口令
	TThostFtdcPasswordType	NewPassword;
};

///输入报单
struct CThostFtdcInputOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///报单价格条件
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	TThostFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TThostFtdcVolumeType	MinVolume;
	///触发条件
	TThostFtdcContingentConditionType	ContingentCondition;
	///止损价
	TThostFtdcPriceType	StopPrice;
	///强平原因
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TThostFtdcBoolType	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///用户强评标志
	TThostFtdcBoolType	UserForceClose;
	///互换单标志
	TThostFtdcBoolType	IsSwapOrder;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
};

///报单
struct CThostFtdcOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///报单价格条件
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	TThostFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TThostFtdcVolumeType	MinVolume;
	///触发条件
	TThostFtdcContingentConditionType	ContingentCondition;
	///止损价
	TThostFtdcPriceType	StopPrice;
	///强平原因
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TThostFtdcBoolType	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///报单提交状态
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///报单提示序号
	TThostFtdcSequenceNoType	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///报单来源
	TThostFtdcOrderSourceType	OrderSource;
	///报单状态
	TThostFtdcOrderStatusType	OrderStatus;
	///报单类型
	TThostFtdcOrderTypeType	OrderType;
	///今成交数量
	TThostFtdcVolumeType	VolumeTraded;
	///剩余数量
	TThostFtdcVolumeType	VolumeTotal;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///委托时间
	TThostFtdcTimeType	InsertTime;
	///激活时间
	TThostFtdcTimeType	ActiveTime;
	///挂起时间
	TThostFtdcTimeType	SuspendTime;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///最后修改交易所交易员代码
	TThostFtdcTraderIDType	ActiveTraderID;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///用户强评标志
	TThostFtdcBoolType	UserForceClose;
	///操作用户代码
	TThostFtdcUserIDType	ActiveUserID;
	///经纪公司报单编号
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	///相关报单
	TThostFtdcOrderSysIDType	RelativeOrderSysID;
	///郑商所成交数量
	TThostFtdcVolumeType	ZCETotalTradedVolume;
	///互换单标志
	TThostFtdcBoolType	IsSwapOrder;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///交易所报单
struct CThostFtdcExchangeOrderField
{
	///报单价格条件
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	TThostFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TThostFtdcVolumeType	MinVolume;
	///触发条件
	TThostFtdcContingentConditionType	ContingentCondition;
	///止损价
	TThostFtdcPriceType	StopPrice;
	///强平原因
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TThostFtdcBoolType	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///报单提交状态
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///报单提示序号
	TThostFtdcSequenceNoType	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///报单来源
	TThostFtdcOrderSourceType	OrderSource;
	///报单状态
	TThostFtdcOrderStatusType	OrderStatus;
	///报单类型
	TThostFtdcOrderTypeType	OrderType;
	///今成交数量
	TThostFtdcVolumeType	VolumeTraded;
	///剩余数量
	TThostFtdcVolumeType	VolumeTotal;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///委托时间
	TThostFtdcTimeType	InsertTime;
	///激活时间
	TThostFtdcTimeType	ActiveTime;
	///挂起时间
	TThostFtdcTimeType	SuspendTime;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///最后修改交易所交易员代码
	TThostFtdcTraderIDType	ActiveTraderID;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///报单回报类型
	TThostFtdcOrderReturnTypeType	OrderReturnType;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
};

///交易所报单插入失败
struct CThostFtdcExchangeOrderInsertErrorField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///输入报单操作
struct CThostFtdcInputOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	TThostFtdcOrderActionRefType	OrderActionRef;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量变化
	TThostFtdcVolumeType	VolumeChange;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///止损价
	TThostFtdcPriceType	StopPrice;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///报单操作
struct CThostFtdcOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	TThostFtdcOrderActionRefType	OrderActionRef;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量变化
	TThostFtdcVolumeType	VolumeChange;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///止损价
	TThostFtdcPriceType	StopPrice;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///交易所报单操作
struct CThostFtdcExchangeOrderActionField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量变化
	TThostFtdcVolumeType	VolumeChange;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///止损价
	TThostFtdcPriceType	StopPrice;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///报单价格条件
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///触发条件
	TThostFtdcContingentConditionType	ContingentCondition;
};

///交易所报单操作失败
struct CThostFtdcExchangeOrderActionErrorField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///改单价格
	TThostFtdcPriceType	LimitPrice;
	///改单数量
	TThostFtdcVolumeType	VolumeChange;
	///改单止损价格
	TThostFtdcPriceType	StopPrice;
	///报单价格条件
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///触发条件
	TThostFtdcContingentConditionType	ContingentCondition;
};

///交易所成交
struct CThostFtdcExchangeTradeField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///成交编号
	TThostFtdcTradeIDType	TradeID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///交易角色
	TThostFtdcTradingRoleType	TradingRole;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///开平标志
	TThostFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///价格
	TThostFtdcPriceType	Price;
	///数量
	TThostFtdcVolumeType	Volume;
	///成交时期
	TThostFtdcDateType	TradeDate;
	///成交时间
	TThostFtdcTimeType	TradeTime;
	///成交类型
	TThostFtdcTradeTypeType	TradeType;
	///成交价来源
	TThostFtdcPriceSourceType	PriceSource;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
};

///成交
struct CThostFtdcTradeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///成交编号
	TThostFtdcTradeIDType	TradeID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///交易角色
	TThostFtdcTradingRoleType	TradingRole;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///开平标志
	TThostFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///价格
	TThostFtdcPriceType	Price;
	///数量
	TThostFtdcVolumeType	Volume;
	///成交日期
	TThostFtdcDateType	TradeDate;
	///成交时间
	TThostFtdcTimeType	TradeTime;
	///成交类型
	TThostFtdcTradeTypeType	TradeType;
	///成交价来源
	TThostFtdcPriceSourceType	PriceSource;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///经纪公司报单编号
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	///成交来源
	TThostFtdcTradeSourceType	TradeSource;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///用户会话
struct CThostFtdcUserSessionField
{
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///登录日期
	TThostFtdcDateType	LoginDate;
	///登录时间
	TThostFtdcTimeType	LoginTime;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
	///语言类型
	TThostFtdcLanguageTypeType	Lang;
	///用户类型
	TThostFtdcUserTypeType	UserType;
	///是否已登录
	TThostFtdcBoolType	IsLogin;
	///登录备注
	TThostFtdcRemarkType	Remark;
};

///查询最大报单数量
struct CThostFtdcQueryMaxOrderVolumeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///开平标志
	TThostFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///最大允许报单数量
	TThostFtdcVolumeType	MaxVolume;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///投资者结算结果确认信息
struct CThostFtdcInvestorSettlementInfoConfirmField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///确认日期
	TThostFtdcDateType	ConfirmDate;
	///确认时间
	TThostFtdcTimeType	ConfirmTime;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///出入金同步
struct CThostFtdcSyncDepositField
{
	///出入金流水号
	TThostFtdcDepositSeqNoType	DepositSeqNo;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcAccountIDType	AccountID;
	///入金金额
	TThostFtdcMoneyType	Deposit;
	///是否强制进行
	TThostFtdcBoolType	IsForce;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///货币质押同步
struct CThostFtdcSyncFundMortgageField
{
	///货币质押流水号
	TThostFtdcDepositSeqNoType	MortgageSeqNo;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///源币种帐号
	TThostFtdcAccountIDType	SourceAccountID;
	///目标币种帐号
	TThostFtdcAccountIDType	TargetAccountID;
	///源币种
	TThostFtdcCurrencyIDType	SourceCurrencyID;
	///目标币种
	TThostFtdcCurrencyIDType	TargetCurrencyID;
	///质押金额
	TThostFtdcMoneyType	MortgageAmount;
};

///查询报单
struct CThostFtdcQryOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///开始时间
	TThostFtdcTimeType	InsertTimeStart;
	///结束时间
	TThostFtdcTimeType	InsertTimeEnd;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询成交
struct CThostFtdcQryTradeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///成交编号
	TThostFtdcTradeIDType	TradeID;
	///开始时间
	TThostFtdcTimeType	TradeTimeStart;
	///结束时间
	TThostFtdcTimeType	TradeTimeEnd;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询投资者持仓
struct CThostFtdcQryInvestorPositionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询资金账户
struct CThostFtdcQryTradingAccountField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///查询投资者
struct CThostFtdcQryInvestorField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///查询交易编码
struct CThostFtdcQryTradingCodeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///交易编码类型
	TThostFtdcClientIDModeType	ClientIDMode;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询投资者组
struct CThostFtdcQryInvestorGroupField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///查询合约保证金率
struct CThostFtdcQryInstrumentMarginRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询手续费率
struct CThostFtdcQryInstrumentCommissionRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询合约交易权限
struct CThostFtdcQryInstrumentTradingRightField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询经纪公司
struct CThostFtdcQryBrokerField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///查询交易员
struct CThostFtdcQryTraderField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///查询管理用户功能权限
struct CThostFtdcQrySuperUserFunctionField
{
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///查询用户会话
struct CThostFtdcQryUserSessionField
{
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///查询经纪公司会员代码
struct CThostFtdcQryPartBrokerField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
};

///查询交易所报单
struct CThostFtdcQryExchangeOrderField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///查询报单操作
struct CThostFtdcQryOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///查询交易所报单操作
struct CThostFtdcQryExchangeOrderActionField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///查询管理用户
struct CThostFtdcQrySuperUserField
{
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///查询交易所
struct CThostFtdcQryExchangeField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///查询产品
struct CThostFtdcQryProductField
{
	///品种代码
	TThostFtdcProductIDType	ProductID;
	///产品类型
	TThostFtdcProductClassType	ProductClass;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所子市场代码
	TThostFtdcSubExchangeIDType	SubExchangeID;
};

///查询合约
struct CThostFtdcQryInstrumentField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///品种代码
	TThostFtdcProductIDType	ProductID;
	///交易所子市场代码
	TThostFtdcSubExchangeIDType	SubExchangeID;
};

///查询行情
struct CThostFtdcQryDepthMarketDataField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///查询经纪公司用户
struct CThostFtdcQryBrokerUserField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///查询经纪公司用户权限
struct CThostFtdcQryBrokerUserFunctionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///查询投资单元
struct CThostFtdcQryInvestUnitField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询交易员报盘机
struct CThostFtdcQryTraderOfferField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///查询出入金流水
struct CThostFtdcQrySyncDepositField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///出入金流水号
	TThostFtdcDepositSeqNoType	DepositSeqNo;
};

///查询投资者结算结果
struct CThostFtdcQryInvestorSettlementInfoField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易日
	TThostFtdcDateType	TradingDay;
};

///查询交易所保证金率
struct CThostFtdcQryExchangeMarginRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///查询汇率
struct CThostFtdcQryExchangeRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///源币种
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///目标币种
	TThostFtdcCurrencyIDType	ToCurrencyID;
};

///查询货币质押流水
struct CThostFtdcQrySyncFundMortgageField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///货币质押流水号
	TThostFtdcDepositSeqNoType	MortgageSeqNo;
};

///当前期权合约最小保证金
struct CThostFtdcOptionInstrMiniMarginField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///单位（手）期权合约最小保证金
	TThostFtdcMoneyType	MinMargin;
	///取值方式
	TThostFtdcValueMethodType	ValueMethod;
	///是否跟随交易所收取
	TThostFtdcBoolType	IsRelative;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///当前期权合约保证金调整系数
struct CThostFtdcOptionInstrMarginAdjustField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投机空头保证金调整系数
	TThostFtdcRatioType	SShortMarginRatioByMoney;
	///投机空头保证金调整系数
	TThostFtdcMoneyType	SShortMarginRatioByVolume;
	///保值空头保证金调整系数
	TThostFtdcRatioType	HShortMarginRatioByMoney;
	///保值空头保证金调整系数
	TThostFtdcMoneyType	HShortMarginRatioByVolume;
	///套利空头保证金调整系数
	TThostFtdcRatioType	AShortMarginRatioByMoney;
	///套利空头保证金调整系数
	TThostFtdcMoneyType	AShortMarginRatioByVolume;
	///是否跟随交易所收取
	TThostFtdcBoolType	IsRelative;
	///做市商空头保证金调整系数
	TThostFtdcRatioType	MShortMarginRatioByMoney;
	///做市商空头保证金调整系数
	TThostFtdcMoneyType	MShortMarginRatioByVolume;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///当前期权合约手续费的详细内容
struct CThostFtdcOptionInstrCommRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///开仓手续费率
	TThostFtdcRatioType	OpenRatioByMoney;
	///开仓手续费
	TThostFtdcRatioType	OpenRatioByVolume;
	///平仓手续费率
	TThostFtdcRatioType	CloseRatioByMoney;
	///平仓手续费
	TThostFtdcRatioType	CloseRatioByVolume;
	///平今手续费率
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///平今手续费
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///执行手续费率
	TThostFtdcRatioType	StrikeRatioByMoney;
	///执行手续费
	TThostFtdcRatioType	StrikeRatioByVolume;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
};

///期权交易成本
struct CThostFtdcOptionInstrTradeCostField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///期权合约保证金不变部分
	TThostFtdcMoneyType	FixedMargin;
	///期权合约最小保证金
	TThostFtdcMoneyType	MiniMargin;
	///期权合约权利金
	TThostFtdcMoneyType	Royalty;
	///交易所期权合约保证金不变部分
	TThostFtdcMoneyType	ExchFixedMargin;
	///交易所期权合约最小保证金
	TThostFtdcMoneyType	ExchMiniMargin;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///期权交易成本查询
struct CThostFtdcQryOptionInstrTradeCostField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///期权合约报价
	TThostFtdcPriceType	InputPrice;
	///标的价格,填0则用昨结算价
	TThostFtdcPriceType	UnderlyingPrice;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///期权手续费率查询
struct CThostFtdcQryOptionInstrCommRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///股指现货指数
struct CThostFtdcIndexPriceField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///指数现货收盘价
	TThostFtdcPriceType	ClosePrice;
};

///输入的执行宣告
struct CThostFtdcInputExecOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///数量
	TThostFtdcVolumeType	Volume;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///开平标志
	TThostFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///执行类型
	TThostFtdcActionTypeType	ActionType;
	///保留头寸申请的持仓方向
	TThostFtdcPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
};

///输入执行宣告操作
struct CThostFtdcInputExecOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///执行宣告操作引用
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告操作编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///执行宣告
struct CThostFtdcExecOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///数量
	TThostFtdcVolumeType	Volume;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///开平标志
	TThostFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///执行类型
	TThostFtdcActionTypeType	ActionType;
	///保留头寸申请的持仓方向
	TThostFtdcPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///本地执行宣告编号
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///执行宣告提交状态
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///报单提示序号
	TThostFtdcSequenceNoType	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///执行宣告编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///执行结果
	TThostFtdcExecResultType	ExecResult;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///操作用户代码
	TThostFtdcUserIDType	ActiveUserID;
	///经纪公司报单编号
	TThostFtdcSequenceNoType	BrokerExecOrderSeq;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///执行宣告操作
struct CThostFtdcExecOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///执行宣告操作引用
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告操作编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///本地执行宣告编号
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///执行类型
	TThostFtdcActionTypeType	ActionType;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///执行宣告查询
struct CThostFtdcQryExecOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///开始时间
	TThostFtdcTimeType	InsertTimeStart;
	///结束时间
	TThostFtdcTimeType	InsertTimeEnd;
};

///交易所执行宣告信息
struct CThostFtdcExchangeExecOrderField
{
	///数量
	TThostFtdcVolumeType	Volume;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///开平标志
	TThostFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///执行类型
	TThostFtdcActionTypeType	ActionType;
	///保留头寸申请的持仓方向
	TThostFtdcPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///本地执行宣告编号
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///执行宣告提交状态
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///报单提示序号
	TThostFtdcSequenceNoType	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///执行宣告编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///执行结果
	TThostFtdcExecResultType	ExecResult;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
};

///交易所执行宣告查询
struct CThostFtdcQryExchangeExecOrderField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///执行宣告操作查询
struct CThostFtdcQryExecOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///交易所执行宣告操作
struct CThostFtdcExchangeExecOrderActionField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告操作编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///本地执行宣告编号
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///执行类型
	TThostFtdcActionTypeType	ActionType;
};

///交易所执行宣告操作查询
struct CThostFtdcQryExchangeExecOrderActionField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///错误执行宣告
struct CThostFtdcErrExecOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///数量
	TThostFtdcVolumeType	Volume;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///开平标志
	TThostFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///执行类型
	TThostFtdcActionTypeType	ActionType;
	///保留头寸申请的持仓方向
	TThostFtdcPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///查询错误执行宣告
struct CThostFtdcQryErrExecOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///错误执行宣告操作
struct CThostFtdcErrExecOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///执行宣告操作引用
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告操作编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///查询错误执行宣告操作
struct CThostFtdcQryErrExecOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///投资者期权合约交易权限
struct CThostFtdcOptionInstrTradingRightField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///交易权限
	TThostFtdcTradingRightType	TradingRight;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询期权合约交易权限
struct CThostFtdcQryOptionInstrTradingRightField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///输入的询价
struct CThostFtdcInputForQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///询价引用
	TThostFtdcOrderRefType	ForQuoteRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///询价
struct CThostFtdcForQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///询价引用
	TThostFtdcOrderRefType	ForQuoteRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///本地询价编号
	TThostFtdcOrderLocalIDType	ForQuoteLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///询价状态
	TThostFtdcForQuoteStatusType	ForQuoteStatus;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///操作用户代码
	TThostFtdcUserIDType	ActiveUserID;
	///经纪公司询价编号
	TThostFtdcSequenceNoType	BrokerForQutoSeq;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///询价查询
struct CThostFtdcQryForQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///开始时间
	TThostFtdcTimeType	InsertTimeStart;
	///结束时间
	TThostFtdcTimeType	InsertTimeEnd;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///交易所询价信息
struct CThostFtdcExchangeForQuoteField
{
	///本地询价编号
	TThostFtdcOrderLocalIDType	ForQuoteLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///询价状态
	TThostFtdcForQuoteStatusType	ForQuoteStatus;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///交易所询价查询
struct CThostFtdcQryExchangeForQuoteField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///输入的报价
struct CThostFtdcInputQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报价引用
	TThostFtdcOrderRefType	QuoteRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///卖价格
	TThostFtdcPriceType	AskPrice;
	///买价格
	TThostFtdcPriceType	BidPrice;
	///卖数量
	TThostFtdcVolumeType	AskVolume;
	///买数量
	TThostFtdcVolumeType	BidVolume;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///卖开平标志
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	///买开平标志
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	///卖投机套保标志
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	///买投机套保标志
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	///衍生卖报单引用
	TThostFtdcOrderRefType	AskOrderRef;
	///衍生买报单引用
	TThostFtdcOrderRefType	BidOrderRef;
	///应价编号
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
};

///输入报价操作
struct CThostFtdcInputQuoteActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报价操作引用
	TThostFtdcOrderActionRefType	QuoteActionRef;
	///报价引用
	TThostFtdcOrderRefType	QuoteRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报价操作编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
};

///报价
struct CThostFtdcQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报价引用
	TThostFtdcOrderRefType	QuoteRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///卖价格
	TThostFtdcPriceType	AskPrice;
	///买价格
	TThostFtdcPriceType	BidPrice;
	///卖数量
	TThostFtdcVolumeType	AskVolume;
	///买数量
	TThostFtdcVolumeType	BidVolume;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///卖开平标志
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	///买开平标志
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	///卖投机套保标志
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	///买投机套保标志
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	///本地报价编号
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///报价提示序号
	TThostFtdcSequenceNoType	NotifySequence;
	///报价提交状态
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///报价编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///报价状态
	TThostFtdcOrderStatusType	QuoteStatus;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///卖方报单编号
	TThostFtdcOrderSysIDType	AskOrderSysID;
	///买方报单编号
	TThostFtdcOrderSysIDType	BidOrderSysID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///操作用户代码
	TThostFtdcUserIDType	ActiveUserID;
	///经纪公司报价编号
	TThostFtdcSequenceNoType	BrokerQuoteSeq;
	///衍生卖报单引用
	TThostFtdcOrderRefType	AskOrderRef;
	///衍生买报单引用
	TThostFtdcOrderRefType	BidOrderRef;
	///应价编号
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///报价操作
struct CThostFtdcQuoteActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报价操作引用
	TThostFtdcOrderActionRefType	QuoteActionRef;
	///报价引用
	TThostFtdcOrderRefType	QuoteRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报价操作编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///本地报价编号
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///报价查询
struct CThostFtdcQryQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报价编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///开始时间
	TThostFtdcTimeType	InsertTimeStart;
	///结束时间
	TThostFtdcTimeType	InsertTimeEnd;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///交易所报价信息
struct CThostFtdcExchangeQuoteField
{
	///卖价格
	TThostFtdcPriceType	AskPrice;
	///买价格
	TThostFtdcPriceType	BidPrice;
	///卖数量
	TThostFtdcVolumeType	AskVolume;
	///买数量
	TThostFtdcVolumeType	BidVolume;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///卖开平标志
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	///买开平标志
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	///卖投机套保标志
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	///买投机套保标志
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	///本地报价编号
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///报价提示序号
	TThostFtdcSequenceNoType	NotifySequence;
	///报价提交状态
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///报价编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///报价状态
	TThostFtdcOrderStatusType	QuoteStatus;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///卖方报单编号
	TThostFtdcOrderSysIDType	AskOrderSysID;
	///买方报单编号
	TThostFtdcOrderSysIDType	BidOrderSysID;
	///应价编号
	TThostFtdcOrderSysIDType	ForQuoteSysID;
};

///交易所报价查询
struct CThostFtdcQryExchangeQuoteField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///报价操作查询
struct CThostFtdcQryQuoteActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///交易所报价操作
struct CThostFtdcExchangeQuoteActionField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报价操作编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///本地报价编号
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///交易所报价操作查询
struct CThostFtdcQryExchangeQuoteActionField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///期权合约delta值
struct CThostFtdcOptionInstrDeltaField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///Delta值
	TThostFtdcRatioType	Delta;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///发给做市商的询价请求
struct CThostFtdcForQuoteRspField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///询价编号
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///询价时间
	TThostFtdcTimeType	ForQuoteTime;
	///业务日期
	TThostFtdcDateType	ActionDay;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///当前期权合约执行偏移值的详细内容
struct CThostFtdcStrikeOffsetField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///执行偏移值
	TThostFtdcMoneyType	Offset;
};

///期权执行偏移值查询
struct CThostFtdcQryStrikeOffsetField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///输入批量报单操作
struct CThostFtdcInputBatchOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	TThostFtdcOrderActionRefType	OrderActionRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///批量报单操作
struct CThostFtdcBatchOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	TThostFtdcOrderActionRefType	OrderActionRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///交易所批量报单操作
struct CThostFtdcExchangeBatchOrderActionField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询批量报单操作
struct CThostFtdcQryBatchOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///组合合约安全系数
struct CThostFtdcCombInstrumentGuardField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///
	TThostFtdcRatioType	GuarantRatio;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///组合合约安全系数查询
struct CThostFtdcQryCombInstrumentGuardField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///输入的申请组合
struct CThostFtdcInputCombActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///组合引用
	TThostFtdcOrderRefType	CombActionRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///数量
	TThostFtdcVolumeType	Volume;
	///组合指令方向
	TThostFtdcCombDirectionType	CombDirection;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///申请组合
struct CThostFtdcCombActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///组合引用
	TThostFtdcOrderRefType	CombActionRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///数量
	TThostFtdcVolumeType	Volume;
	///组合指令方向
	TThostFtdcCombDirectionType	CombDirection;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///本地申请组合编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///组合状态
	TThostFtdcOrderActionStatusType	ActionStatus;
	///报单提示序号
	TThostFtdcSequenceNoType	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///申请组合查询
struct CThostFtdcQryCombActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///交易所申请组合信息
struct CThostFtdcExchangeCombActionField
{
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///数量
	TThostFtdcVolumeType	Volume;
	///组合指令方向
	TThostFtdcCombDirectionType	CombDirection;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///本地申请组合编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///组合状态
	TThostFtdcOrderActionStatusType	ActionStatus;
	///报单提示序号
	TThostFtdcSequenceNoType	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
};

///交易所申请组合查询
struct CThostFtdcQryExchangeCombActionField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///产品报价汇率
struct CThostFtdcProductExchRateField
{
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
	///报价币种类型
	TThostFtdcCurrencyIDType	QuoteCurrencyID;
	///汇率
	TThostFtdcExchangeRateType	ExchangeRate;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///产品报价汇率查询
struct CThostFtdcQryProductExchRateField
{
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///查询询价价差参数
struct CThostFtdcQryForQuoteParamField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///询价价差参数
struct CThostFtdcForQuoteParamField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///最新价
	TThostFtdcPriceType	LastPrice;
	///价差
	TThostFtdcPriceType	PriceInterval;
};

///当前报单手续费的详细内容
struct CThostFtdcOrderCommRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///报单手续费
	TThostFtdcRatioType	OrderCommByVolume;
	///撤单手续费
	TThostFtdcRatioType	OrderActionCommByVolume;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///报单手续费率查询
struct CThostFtdcQryOrderCommRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///市场行情
struct CThostFtdcMarketDataField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///最新价
	TThostFtdcPriceType	LastPrice;
	///上次结算价
	TThostFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TThostFtdcPriceType	PreClosePrice;
	///昨持仓量
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///今开盘
	TThostFtdcPriceType	OpenPrice;
	///最高价
	TThostFtdcPriceType	HighestPrice;
	///最低价
	TThostFtdcPriceType	LowestPrice;
	///数量
	TThostFtdcVolumeType	Volume;
	///成交金额
	TThostFtdcMoneyType	Turnover;
	///持仓量
	TThostFtdcLargeVolumeType	OpenInterest;
	///今收盘
	TThostFtdcPriceType	ClosePrice;
	///本次结算价
	TThostFtdcPriceType	SettlementPrice;
	///涨停板价
	TThostFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TThostFtdcPriceType	LowerLimitPrice;
	///昨虚实度
	TThostFtdcRatioType	PreDelta;
	///今虚实度
	TThostFtdcRatioType	CurrDelta;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TThostFtdcMillisecType	UpdateMillisec;
	///业务日期
	TThostFtdcDateType	ActionDay;
};

///MdFront成交均价
struct CThostFtdcMarketDataAveragePriceCmplField
{
	///当日均价
	TThostFtdcInt64PriceType	AveragePrice;
};

///MdFront行情基础属性
struct CThostFtdcMarketDataBaseCmplField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///上次结算价
	TThostFtdcInt64PriceType	PreSettlementPrice;
	///昨收盘
	TThostFtdcInt64PriceType	PreClosePrice;
	///昨持仓量
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TThostFtdcRatioType	PreDelta;
};

///MdFront行情静态属性
struct CThostFtdcMarketDataStaticCmplField
{
	///今开盘
	TThostFtdcInt64PriceType	OpenPrice;
	///最高价
	TThostFtdcInt64PriceType	HighestPrice;
	///最低价
	TThostFtdcInt64PriceType	LowestPrice;
	///今收盘
	TThostFtdcInt64PriceType	ClosePrice;
	///涨停板价
	TThostFtdcInt64PriceType	UpperLimitPrice;
	///跌停板价
	TThostFtdcInt64PriceType	LowerLimitPrice;
	///本次结算价
	TThostFtdcInt64PriceType	SettlementPrice;
	///今虚实度
	TThostFtdcRatioType	CurrDelta;
};

///MdFront行情最新成交属性
struct CThostFtdcMarketDataLastMatchCmplField
{
	///最新价
	TThostFtdcInt64PriceType	LastPrice;
	///数量
	TThostFtdcVolumeType	Volume;
	///成交金额
	TThostFtdcMoneyType	Turnover;
	///持仓量
	TThostFtdcLargeVolumeType	OpenInterest;
};

///MdFront行情更新时间属性
struct CThostFtdcMarketDataUpdateTimeCmplField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TThostFtdcMillisecType	UpdateMillisec;
	///业务日期
	TThostFtdcDateType	ActionDay;
	///合约行情报文序号
	TThostFtdcSequenceNumType	MDSequenceNum;
	///交易所行情报文序号
	TThostFtdcSequenceNumType	RptSeq;
};

///行情基础属性
struct CThostFtdcMarketDataBaseField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///上次结算价
	TThostFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TThostFtdcPriceType	PreClosePrice;
	///昨持仓量
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TThostFtdcRatioType	PreDelta;
};

///行情静态属性
struct CThostFtdcMarketDataStaticField
{
	///今开盘
	TThostFtdcPriceType	OpenPrice;
	///最高价
	TThostFtdcPriceType	HighestPrice;
	///最低价
	TThostFtdcPriceType	LowestPrice;
	///今收盘
	TThostFtdcPriceType	ClosePrice;
	///涨停板价
	TThostFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TThostFtdcPriceType	LowerLimitPrice;
	///本次结算价
	TThostFtdcPriceType	SettlementPrice;
	///今虚实度
	TThostFtdcRatioType	CurrDelta;
};

///行情最新成交属性
struct CThostFtdcMarketDataLastMatchField
{
	///最新价
	TThostFtdcPriceType	LastPrice;
	///数量
	TThostFtdcVolumeType	Volume;
	///成交金额
	TThostFtdcMoneyType	Turnover;
	///持仓量
	TThostFtdcLargeVolumeType	OpenInterest;
};

///行情最优价属性
struct CThostFtdcMarketDataBestPriceField
{
	///申买价一
	TThostFtdcPriceType	BidPrice1;
	///申买量一
	TThostFtdcVolumeType	BidVolume1;
	///申卖价一
	TThostFtdcPriceType	AskPrice1;
	///申卖量一
	TThostFtdcVolumeType	AskVolume1;
};

///行情申买二、三属性
struct CThostFtdcMarketDataBid23Field
{
	///申买价二
	TThostFtdcPriceType	BidPrice2;
	///申买量二
	TThostFtdcVolumeType	BidVolume2;
	///申买价三
	TThostFtdcPriceType	BidPrice3;
	///申买量三
	TThostFtdcVolumeType	BidVolume3;
};

///行情申卖二、三属性
struct CThostFtdcMarketDataAsk23Field
{
	///申卖价二
	TThostFtdcPriceType	AskPrice2;
	///申卖量二
	TThostFtdcVolumeType	AskVolume2;
	///申卖价三
	TThostFtdcPriceType	AskPrice3;
	///申卖量三
	TThostFtdcVolumeType	AskVolume3;
};

///行情申买四、五属性
struct CThostFtdcMarketDataBid45Field
{
	///申买价四
	TThostFtdcPriceType	BidPrice4;
	///申买量四
	TThostFtdcVolumeType	BidVolume4;
	///申买价五
	TThostFtdcPriceType	BidPrice5;
	///申买量五
	TThostFtdcVolumeType	BidVolume5;
};

///行情申卖四、五属性
struct CThostFtdcMarketDataAsk45Field
{
	///申卖价四
	TThostFtdcPriceType	AskPrice4;
	///申卖量四
	TThostFtdcVolumeType	AskVolume4;
	///申卖价五
	TThostFtdcPriceType	AskPrice5;
	///申卖量五
	TThostFtdcVolumeType	AskVolume5;
};

///行情更新时间属性
struct CThostFtdcMarketDataUpdateTimeField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TThostFtdcMillisecType	UpdateMillisec;
	///业务日期
	TThostFtdcDateType	ActionDay;
};

///行情申买六、七属性
struct CThostFtdcMarketDataBid67Field
{
	///申买价六
	TThostFtdcPriceType	BidPrice6;
	///申买量六
	TThostFtdcVolumeType	BidVolume6;
	///申买价七
	TThostFtdcPriceType	BidPrice7;
	///申买量七
	TThostFtdcVolumeType	BidVolume7;
};

///行情申卖六、七属性
struct CThostFtdcMarketDataAsk67Field
{
	///申卖价六
	TThostFtdcPriceType	AskPrice6;
	///申卖量六
	TThostFtdcVolumeType	AskVolume6;
	///申卖价七
	TThostFtdcPriceType	AskPrice7;
	///申卖量七
	TThostFtdcVolumeType	AskVolume7;
};

///行情申买八、九属性
struct CThostFtdcMarketDataBid89Field
{
	///申买价八
	TThostFtdcPriceType	BidPrice8;
	///申买量八
	TThostFtdcVolumeType	BidVolume8;
	///申买价九
	TThostFtdcPriceType	BidPrice9;
	///申买量九
	TThostFtdcVolumeType	BidVolume9;
};

///行情申卖八、九属性
struct CThostFtdcMarketDataAsk89Field
{
	///申卖价八
	TThostFtdcPriceType	AskPrice8;
	///申卖量八
	TThostFtdcVolumeType	AskVolume8;
	///申卖价九
	TThostFtdcPriceType	AskPrice9;
	///申卖量九
	TThostFtdcVolumeType	AskVolume9;
};

///行情申买、卖十属性
struct CThostFtdcMarketData10Field
{
	///申卖价十
	TThostFtdcPriceType	AskPrice10;
	///申卖量十
	TThostFtdcVolumeType	AskVolume10;
	///申买价十
	TThostFtdcPriceType	BidPrice10;
	///申买量十
	TThostFtdcVolumeType	BidVolume10;
};

///行情交易所代码属性
struct CThostFtdcMarketDataExchangeField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///指定的合约
struct CThostFtdcSpecificInstrumentField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///合约状态
struct CThostFtdcInstrumentStatusField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///结算组代码
	TThostFtdcSettlementGroupIDType	SettlementGroupID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TThostFtdcInstrumentStatusType	InstrumentStatus;
	///交易阶段编号
	TThostFtdcTradingSegmentSNType	TradingSegmentSN;
	///进入本状态时间
	TThostFtdcTimeType	EnterTime;
	///进入本状态原因
	TThostFtdcInstStatusEnterReasonType	EnterReason;
	///进入本状态日期
	TThostFtdcDateType	EnterDate;
};

///查询合约状态
struct CThostFtdcQryInstrumentStatusField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///浮动盈亏算法
struct CThostFtdcPositionProfitAlgorithmField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///盈亏算法
	TThostFtdcAlgorithmType	Algorithm;
	///备注
	TThostFtdcMemoType	Memo;
};

///查询转帐银行
struct CThostFtdcQryTransferBankField
{
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分中心代码
	TThostFtdcBankBrchIDType	BankBrchID;
};

///转帐银行
struct CThostFtdcTransferBankField
{
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分中心代码
	TThostFtdcBankBrchIDType	BankBrchID;
	///银行名称
	TThostFtdcBankNameType	BankName;
	///是否活跃
	TThostFtdcBoolType	IsActive;
};

///查询投资者持仓明细
struct CThostFtdcQryInvestorPositionDetailField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///投资者持仓明细
struct CThostFtdcInvestorPositionDetailField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///开仓日期
	TThostFtdcDateType	OpenDate;
	///成交编号
	TThostFtdcTradeIDType	TradeID;
	///数量
	TThostFtdcVolumeType	Volume;
	///开仓价
	TThostFtdcPriceType	OpenPrice;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///成交类型
	TThostFtdcTradeTypeType	TradeType;
	///组合合约代码
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///逐日盯市平仓盈亏
	TThostFtdcMoneyType	CloseProfitByDate;
	///逐笔对冲平仓盈亏
	TThostFtdcMoneyType	CloseProfitByTrade;
	///逐日盯市持仓盈亏
	TThostFtdcMoneyType	PositionProfitByDate;
	///逐笔对冲持仓盈亏
	TThostFtdcMoneyType	PositionProfitByTrade;
	///投资者保证金
	TThostFtdcMoneyType	Margin;
	///交易所保证金
	TThostFtdcMoneyType	ExchMargin;
	///保证金率
	TThostFtdcRatioType	MarginRateByMoney;
	///保证金率(按手数)
	TThostFtdcRatioType	MarginRateByVolume;
	///昨结算价
	TThostFtdcPriceType	LastSettlementPrice;
	///结算价
	TThostFtdcPriceType	SettlementPrice;
	///平仓量
	TThostFtdcVolumeType	CloseVolume;
	///平仓金额
	TThostFtdcMoneyType	CloseAmount;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///投资者维持保证金
	TThostFtdcMoneyType	MaintenMargin;
	///交易所维持保证金
	TThostFtdcMoneyType	ExchMaintenMargin;
	///维持保证金率
	TThostFtdcRatioType	MaintenMarginRateByMoney;
	///维持保证金率(按手数)
	TThostFtdcRatioType	MaintenMarginRateByVolume;
};

///资金账户口令域
struct CThostFtdcTradingAccountPasswordField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///密码
	TThostFtdcPasswordType	Password;
};

///交易所行情报盘机
struct CThostFtdcMDTraderOfferField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///密码
	TThostFtdcPasswordType	Password;
	///应用名称
	TThostFtdcAppNameType	AppName;
	///运行编号
	TThostFtdcRunIDType	RunID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///IP限制范围
	TThostFtdcIPAddressType	IpRange;
	///交易所交易员连接状态
	TThostFtdcTraderConnectStatusType	TraderConnectStatus;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///发出连接请求的日期
	TThostFtdcDateType	ConnectRequestDate;
	///发出连接请求的时间
	TThostFtdcTimeType	ConnectRequestTime;
	///上次报告日期
	TThostFtdcDateType	LastReportDate;
	///上次报告时间
	TThostFtdcTimeType	LastReportTime;
	///完成连接日期
	TThostFtdcDateType	ConnectDate;
	///完成连接时间
	TThostFtdcTimeType	ConnectTime;
	///启动日期
	TThostFtdcDateType	StartDate;
	///启动时间
	TThostFtdcTimeType	StartTime;
	///交易日
	TThostFtdcDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///经纪公司类型
	TThostFtdcPartTypeType	ParticipantType;
};

///查询行情报盘机
struct CThostFtdcQryMDTraderOfferField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///查询客户通知
struct CThostFtdcQryNoticeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///客户通知
struct CThostFtdcNoticeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///消息正文
	TThostFtdcContentType	Content;
	///序列号
	TThostFtdcSequenceLabelType	SequenceLabel;
};

///用户权限
struct CThostFtdcUserRightField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///客户权限类型
	TThostFtdcUserRightTypeType	UserRightType;
	///是否禁止
	TThostFtdcBoolType	IsForbidden;
};

///查询结算信息确认域
struct CThostFtdcQryInvestorSettlementInfoConfirmField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///经纪公司可提资金算法表
struct CThostFtdcBrokerWithdrawAlgorithmField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///可提资金算法
	TThostFtdcAlgorithmType	WithdrawAlgorithm;
	///资金使用率
	TThostFtdcRatioType	UsingRatio;
	///可提是否包含平仓盈利
	TThostFtdcIncludeCloseProfitType	IncludeCloseProfit;
	///本日无仓且无成交客户是否受可提比例限制
	TThostFtdcAllWithoutTradeType	AllWithoutTrade;
	///可用是否包含平仓盈利
	TThostFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
	///货币质押比率
	TThostFtdcRatioType	FundMortgageRatio;
	///权益算法
	TThostFtdcBalanceAlgorithmType	BalanceAlgorithm;
};

///资金账户口令变更域
struct CThostFtdcTradingAccountPasswordUpdateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///原来的口令
	TThostFtdcPasswordType	OldPassword;
	///新的口令
	TThostFtdcPasswordType	NewPassword;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///查询组合合约分腿
struct CThostFtdcQryCombinationLegField
{
	///组合合约代码
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///单腿编号
	TThostFtdcLegIDType	LegID;
	///单腿合约代码
	TThostFtdcInstrumentIDType	LegInstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///查询同步状态
struct CThostFtdcQrySyncStatusField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///组合交易合约的单腿
struct CThostFtdcCombinationLegField
{
	///组合合约代码
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///单腿编号
	TThostFtdcLegIDType	LegID;
	///单腿合约代码
	TThostFtdcInstrumentIDType	LegInstrumentID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///单腿乘数
	TThostFtdcLegMultipleType	LegMultiple;
	///派生层数
	TThostFtdcImplyLevelType	ImplyLevel;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///数据同步状态
struct CThostFtdcSyncStatusField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///结算序列号
	TThostFtdcSequenceNoType	SettlementNo;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///数据同步状态
	TThostFtdcDataSyncStatusType	DataSyncStatus;
};

///查询联系人
struct CThostFtdcQryLinkManField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///联系人
struct CThostFtdcLinkManField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///联系人类型
	TThostFtdcPersonTypeType	PersonType;
	///证件类型
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///名称
	TThostFtdcPartyNameType	PersonName;
	///联系电话
	TThostFtdcTelephoneType	Telephone;
	///通讯地址
	TThostFtdcAddressType	Address;
	///邮政编码
	TThostFtdcZipCodeType	ZipCode;
	///优先级
	TThostFtdcPriorityType	Priority;
	///开户邮政编码
	TThostFtdcUOAZipCodeType	UOAZipCode;
	///全称
	TThostFtdcInvestorFullNameType	PersonFullName;
};

///查询经纪公司用户事件
struct CThostFtdcQryBrokerUserEventField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户事件类型
	TThostFtdcUserEventTypeType	UserEventType;
};

///查询经纪公司用户事件
struct CThostFtdcBrokerUserEventField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户事件类型
	TThostFtdcUserEventTypeType	UserEventType;
	///用户事件序号
	TThostFtdcSequenceNoType	EventSequenceNo;
	///事件发生日期
	TThostFtdcDateType	EventDate;
	///事件发生时间
	TThostFtdcTimeType	EventTime;
	///用户事件信息
	TThostFtdcUserEventInfoType	UserEventInfo;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询签约银行请求
struct CThostFtdcQryContractBankField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分中心代码
	TThostFtdcBankBrchIDType	BankBrchID;
};

///查询签约银行响应
struct CThostFtdcContractBankField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分中心代码
	TThostFtdcBankBrchIDType	BankBrchID;
	///银行名称
	TThostFtdcBankNameType	BankName;
};

///投资者组合持仓明细
struct CThostFtdcInvestorPositionCombineDetailField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///开仓日期
	TThostFtdcDateType	OpenDate;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///组合编号
	TThostFtdcTradeIDType	ComTradeID;
	///成交编号
	TThostFtdcTradeIDType	TradeID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///持仓量
	TThostFtdcVolumeType	TotalAmt;
	///投资者保证金
	TThostFtdcMoneyType	Margin;
	///交易所保证金
	TThostFtdcMoneyType	ExchMargin;
	///保证金率
	TThostFtdcRatioType	MarginRateByMoney;
	///保证金率(按手数)
	TThostFtdcRatioType	MarginRateByVolume;
	///单腿编号
	TThostFtdcLegIDType	LegID;
	///单腿乘数
	TThostFtdcLegMultipleType	LegMultiple;
	///组合持仓合约编码
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///成交组号
	TThostFtdcTradeGroupIDType	TradeGroupID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
};

///预埋单
struct CThostFtdcPrePayOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///报单价格条件
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	TThostFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TThostFtdcVolumeType	MinVolume;
	///触发条件
	TThostFtdcContingentConditionType	ContingentCondition;
	///止损价
	TThostFtdcPriceType	StopPrice;
	///强平原因
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TThostFtdcBoolType	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///用户强评标志
	TThostFtdcBoolType	UserForceClose;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///预埋报单编号
	TThostFtdcPrePayOrderIDType	PrePayOrderID;
	///用户类型
	TThostFtdcUserTypeType	UserType;
	///预埋单状态
	TThostFtdcPrePayOrderStatusType	Status;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///互换单标志
	TThostFtdcBoolType	IsSwapOrder;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///输入预埋单操作
struct CThostFtdcPrePayOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	TThostFtdcOrderActionRefType	OrderActionRef;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量变化
	TThostFtdcVolumeType	VolumeChange;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///预埋撤单编号
	TThostFtdcPrePayOrderIDType	PrePayOrderActionID;
	///用户类型
	TThostFtdcUserTypeType	UserType;
	///预埋撤单状态
	TThostFtdcPrePayOrderStatusType	Status;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询预埋单
struct CThostFtdcQryPrePayOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询预埋撤单
struct CThostFtdcQryPrePayOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///删除预埋单
struct CThostFtdcRemovePrePayOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///预埋报单编号
	TThostFtdcPrePayOrderIDType	PrePayOrderID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///删除预埋撤单
struct CThostFtdcRemovePrePayOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///预埋撤单编号
	TThostFtdcPrePayOrderIDType	PrePayOrderActionID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///经纪公司可提资金算法表，CTP一代为投资者可提资金比例
struct CThostFtdcAccountWithdrawAlgorithmField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///资金账户范围
	TThostFtdcAccountRangeType	AccountRange;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///可提资金比例
	TThostFtdcRatioType	UsingRatio;
	///货币质押比率
	TThostFtdcRatioType	FundMortgageRatio;
};

///查询组合持仓明细
struct CThostFtdcQryInvestorPositionCombineDetailField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///组合持仓合约编码
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///成交均价
struct CThostFtdcMarketDataAveragePriceField
{
	///当日均价
	TThostFtdcPriceType	AveragePrice;
};

///校验投资者密码
struct CThostFtdcVerifyInvestorPasswordField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///密码
	TThostFtdcPasswordType	Password;
};

///用户IP
struct CThostFtdcUserIPField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///IP地址掩码
	TThostFtdcIPAddressType	IPMask;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///用户事件通知信息
struct CThostFtdcTradingNoticeInfoField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///发送时间
	TThostFtdcTimeType	SendTime;
	///消息正文
	TThostFtdcContentType	FieldContent;
	///序列系列号
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///用户事件通知
struct CThostFtdcTradingNoticeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者范围
	TThostFtdcInvestorRangeType	InvestorRange;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///序列系列号
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///发送时间
	TThostFtdcTimeType	SendTime;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///消息正文
	TThostFtdcContentType	FieldContent;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询交易事件通知
struct CThostFtdcQryTradingNoticeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询错误报单
struct CThostFtdcQryErrOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///错误报单
struct CThostFtdcErrOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///报单价格条件
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	TThostFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TThostFtdcVolumeType	MinVolume;
	///触发条件
	TThostFtdcContingentConditionType	ContingentCondition;
	///止损价
	TThostFtdcPriceType	StopPrice;
	///强平原因
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TThostFtdcBoolType	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///用户强评标志
	TThostFtdcBoolType	UserForceClose;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///互换单标志
	TThostFtdcBoolType	IsSwapOrder;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///条件单校验错误
struct CThostFtdcErrorConditionalOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///报单价格条件
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	TThostFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TThostFtdcVolumeType	MinVolume;
	///触发条件
	TThostFtdcContingentConditionType	ContingentCondition;
	///止损价
	TThostFtdcPriceType	StopPrice;
	///强平原因
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TThostFtdcBoolType	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///报单提交状态
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///报单提示序号
	TThostFtdcSequenceNoType	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///报单来源
	TThostFtdcOrderSourceType	OrderSource;
	///报单状态
	TThostFtdcOrderStatusType	OrderStatus;
	///报单类型
	TThostFtdcOrderTypeType	OrderType;
	///今成交数量
	TThostFtdcVolumeType	VolumeTraded;
	///剩余数量
	TThostFtdcVolumeType	VolumeTotal;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///委托时间
	TThostFtdcTimeType	InsertTime;
	///激活时间
	TThostFtdcTimeType	ActiveTime;
	///挂起时间
	TThostFtdcTimeType	SuspendTime;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///最后修改交易所交易员代码
	TThostFtdcTraderIDType	ActiveTraderID;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///用户强评标志
	TThostFtdcBoolType	UserForceClose;
	///操作用户代码
	TThostFtdcUserIDType	ActiveUserID;
	///经纪公司报单编号
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	///相关报单
	TThostFtdcOrderSysIDType	RelativeOrderSysID;
	///郑商所成交数量
	TThostFtdcVolumeType	ZCETotalTradedVolume;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///互换单标志
	TThostFtdcBoolType	IsSwapOrder;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///查询错误报单操作
struct CThostFtdcQryErrOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///错误报单操作
struct CThostFtdcErrOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	TThostFtdcOrderActionRefType	OrderActionRef;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	TThostFtdcActionFlagType	ActionFlag;
	///价格
	TThostFtdcPriceType	LimitPrice;
	///数量变化
	TThostFtdcVolumeType	VolumeChange;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///止损价
	TThostFtdcPriceType	StopPrice;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询交易所状态
struct CThostFtdcQryExchangeSequenceField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///交易所状态
struct CThostFtdcExchangeSequenceField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///序号
	TThostFtdcSequenceNoType	SequenceNo;
	///合约交易状态
	TThostFtdcInstrumentStatusType	MarketStatus;
};

///根据价格查询最大报单数量
struct CThostFtdcQueryMaxOrderVolumeWithPriceField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///开平标志
	TThostFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///最大允许报单数量
	TThostFtdcVolumeType	MaxVolume;
	///价格
	TThostFtdcPriceType	Price;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询经纪公司交易参数
struct CThostFtdcQryBrokerTradingParamsField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///经纪公司交易参数
struct CThostFtdcBrokerTradingParamsField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///保证金价格类型
	TThostFtdcMarginPriceTypeType	MarginPriceType;
	///盈亏算法
	TThostFtdcAlgorithmType	Algorithm;
	///可用是否包含平仓盈利
	TThostFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///期权权利金价格类型
	TThostFtdcOptionRoyaltyPriceTypeType	OptionRoyaltyPriceType;
};

///查询经纪公司资金
struct CThostFtdcQueryBrokerDepositField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///经纪公司资金
struct CThostFtdcBrokerDepositField
{
	///交易日期
	TThostFtdcTradeDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///上次结算准备金
	TThostFtdcMoneyType	PreBalance;
	///当前保证金总额
	TThostFtdcMoneyType	CurrMargin;
	///平仓盈亏
	TThostFtdcMoneyType	CloseProfit;
	///期货结算准备金
	TThostFtdcMoneyType	Balance;
	///入金金额
	TThostFtdcMoneyType	Deposit;
	///出金金额
	TThostFtdcMoneyType	Withdraw;
	///可提资金
	TThostFtdcMoneyType	Available;
	///基本准备金
	TThostFtdcMoneyType	Reserve;
	///冻结的保证金
	TThostFtdcMoneyType	FrozenMargin;
};

///用户动态令牌参数
struct CThostFtdcBrokerUserOTPParamField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///动态令牌提供商
	TThostFtdcOTPVendorsIDType	OTPVendorsID;
	///动态令牌序列号
	TThostFtdcSerialNumberType	SerialNumber;
	///令牌密钥
	TThostFtdcAuthKeyType	AuthKey;
	///上次OTP漂移值
	TThostFtdcLastDriftType	LastDrift;
	///上次OTP成功值
	TThostFtdcLastSuccessType	LastSuccess;
	///动态令牌类型
	TThostFtdcOTPTypeType	OTPType;
};

///手工同步用户动态令牌
struct CThostFtdcManualSyncBrokerUserOTPField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///动态令牌类型
	TThostFtdcOTPTypeType	OTPType;
	///第一个动态密码
	TThostFtdcPasswordType	FirstOTP;
	///第二个动态密码
	TThostFtdcPasswordType	SecondOTP;
};

///投资者手续费率模板
struct CThostFtdcCommRateModelField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///手续费率模板代码
	TThostFtdcInvestorIDType	CommModelID;
	///手续费率模板名称
	TThostFtdcCommModelNameType	CommModelName;
};

///请求查询投资者手续费率模板
struct CThostFtdcQryCommRateModelField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///手续费率模板代码
	TThostFtdcInvestorIDType	CommModelID;
};

///投资者保证金率模板
struct CThostFtdcMarginModelField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///保证金率模板代码
	TThostFtdcInvestorIDType	MarginModelID;
	///模板名称
	TThostFtdcCommModelNameType	MarginModelName;
};

///请求查询投资者保证金率模板
struct CThostFtdcQryMarginModelField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///保证金率模板代码
	TThostFtdcInvestorIDType	MarginModelID;
};

///仓单折抵信息
struct CThostFtdcEWarrantOffsetField
{
	///交易日期
	TThostFtdcTradeDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TThostFtdcDirectionType	Direction;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///数量
	TThostFtdcVolumeType	Volume;
	///可用数量
	TThostFtdcVolumeType	CloseVolume;
};

///查询仓单折抵信息
struct CThostFtdcQryEWarrantOffsetField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///查询投资者品种/跨品种保证金
struct CThostFtdcQryInvestorProductGroupMarginField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///品种/跨品种标示
	TThostFtdcInstrumentIDType	ProductGroupID;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///投资者品种/跨品种保证金
struct CThostFtdcInvestorProductGroupMarginField
{
	///品种/跨品种标示
	TThostFtdcInstrumentIDType	ProductGroupID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	TThostFtdcSettlementIDType	SettlementID;
	///冻结的保证金
	TThostFtdcMoneyType	FrozenMargin;
	///多头冻结的保证金
	TThostFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TThostFtdcMoneyType	ShortFrozenMargin;
	///占用的保证金
	TThostFtdcMoneyType	UseMargin;
	///多头保证金
	TThostFtdcMoneyType	LongUseMargin;
	///空头保证金
	TThostFtdcMoneyType	ShortUseMargin;
	///交易所保证金
	TThostFtdcMoneyType	ExchMargin;
	///交易所多头保证金
	TThostFtdcMoneyType	LongExchMargin;
	///交易所空头保证金
	TThostFtdcMoneyType	ShortExchMargin;
	///平仓盈亏
	TThostFtdcMoneyType	CloseProfit;
	///冻结的手续费
	TThostFtdcMoneyType	FrozenCommission;
	///手续费
	TThostFtdcMoneyType	Commission;
	///冻结的资金
	TThostFtdcMoneyType	FrozenCash;
	///资金差额
	TThostFtdcMoneyType	CashIn;
	///持仓盈亏
	TThostFtdcMoneyType	PositionProfit;
	///折抵总金额
	TThostFtdcMoneyType	OffsetAmount;
	///多头折抵总金额
	TThostFtdcMoneyType	LongOffsetAmount;
	///空头折抵总金额
	TThostFtdcMoneyType	ShortOffsetAmount;
	///交易所折抵总金额
	TThostFtdcMoneyType	ExchOffsetAmount;
	///交易所多头折抵总金额
	TThostFtdcMoneyType	LongExchOffsetAmount;
	///交易所空头折抵总金额
	TThostFtdcMoneyType	ShortExchOffsetAmount;
	///投机套保标志
	TThostFtdcHedgeFlagType	HedgeFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///维持保证金
	TThostFtdcMoneyType	MaintenMargin;
	///多头维持保证金
	TThostFtdcMoneyType	LongMaintenMargin;
	///空头维持保证金
	TThostFtdcMoneyType	ShortMaintenMargin;
	///交易所维持保证金
	TThostFtdcMoneyType	ExchMaintenMargin;
	///交易所多头维持保证金
	TThostFtdcMoneyType	LongExchMaintenMargin;
	///交易所空头维持保证金
	TThostFtdcMoneyType	ShortExchMaintenMargin;
};

///查询监控中心用户令牌
struct CThostFtdcQueryCFMMCTradingAccountTokenField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///监控中心用户令牌
struct CThostFtdcCFMMCTradingAccountTokenField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///经纪公司统一编码
	TThostFtdcParticipantIDType	ParticipantID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///密钥编号
	TThostFtdcSequenceNoType	KeyID;
	///动态令牌
	TThostFtdcCFMMCTokenType	Token;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///前置编号
	TThostFtdcFrontIDType	FrontID;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
};

///查询产品组
struct CThostFtdcQryProductGroupField
{
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///投资者品种/跨品种保证金产品组
struct CThostFtdcProductGroupField
{
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///产品组代码
	TThostFtdcInstrumentIDType	ProductGroupID;
};

///转帐开户请求
struct CThostFtdcReqOpenAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	TThostFtdcGenderType	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///汇钞标志
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///交易ID
	TThostFtdcTIDType	TID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
};

///转帐开户响应
struct CThostFtdcRspOpenAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	TThostFtdcGenderType	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///汇钞标志
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///交易ID
	TThostFtdcTIDType	TID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///转帐销户请求
struct CThostFtdcReqCancelAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	TThostFtdcGenderType	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///汇钞标志
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///交易ID
	TThostFtdcTIDType	TID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
};

///转帐销户响应
struct CThostFtdcRspCancelAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	TThostFtdcGenderType	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///汇钞标志
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///交易ID
	TThostFtdcTIDType	TID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///变更银行账户请求
struct CThostFtdcReqChangeAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	TThostFtdcGenderType	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///新银行帐号
	TThostFtdcBankAccountType	NewBankAccount;
	///新银行密码
	TThostFtdcPasswordType	NewBankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易ID
	TThostFtdcTIDType	TID;
	///摘要
	TThostFtdcDigestType	Digest;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
};

///变更银行账户响应
struct CThostFtdcRspChangeAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	TThostFtdcGenderType	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///新银行帐号
	TThostFtdcBankAccountType	NewBankAccount;
	///新银行密码
	TThostFtdcPasswordType	NewBankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易ID
	TThostFtdcTIDType	TID;
	///摘要
	TThostFtdcDigestType	Digest;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///转账请求
struct CThostFtdcReqTransferField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///期货公司流水号
	TThostFtdcFutureSerialType	FutureSerial;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///转帐金额
	TThostFtdcTradeAmountType	TradeAmount;
	///期货可取金额
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///费用支付标志
	TThostFtdcFeePayFlagType	FeePayFlag;
	///应收客户费用
	TThostFtdcCustFeeType	CustFee;
	///应收期货公司费用
	TThostFtdcFutureFeeType	BrokerFee;
	///发送方给接收方的消息
	TThostFtdcAddInfoType	Message;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///转账交易状态
	TThostFtdcTransferStatusType	TransferStatus;
};

///银行发起银行资金转期货响应
struct CThostFtdcRspTransferField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///期货公司流水号
	TThostFtdcFutureSerialType	FutureSerial;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///转帐金额
	TThostFtdcTradeAmountType	TradeAmount;
	///期货可取金额
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///费用支付标志
	TThostFtdcFeePayFlagType	FeePayFlag;
	///应收客户费用
	TThostFtdcCustFeeType	CustFee;
	///应收期货公司费用
	TThostFtdcFutureFeeType	BrokerFee;
	///发送方给接收方的消息
	TThostFtdcAddInfoType	Message;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///转账交易状态
	TThostFtdcTransferStatusType	TransferStatus;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///冲正请求
struct CThostFtdcReqRepealField
{
	///冲正时间间隔
	TThostFtdcRepealTimeIntervalType	RepealTimeInterval;
	///已经冲正次数
	TThostFtdcRepealedTimesType	RepealedTimes;
	///银行冲正标志
	TThostFtdcBankRepealFlagType	BankRepealFlag;
	///期商冲正标志
	TThostFtdcBrokerRepealFlagType	BrokerRepealFlag;
	///被冲正平台流水号
	TThostFtdcPlateSerialType	PlateRepealSerial;
	///被冲正银行流水号
	TThostFtdcBankSerialType	BankRepealSerial;
	///被冲正期货流水号
	TThostFtdcFutureSerialType	FutureRepealSerial;
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///期货公司流水号
	TThostFtdcFutureSerialType	FutureSerial;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///转帐金额
	TThostFtdcTradeAmountType	TradeAmount;
	///期货可取金额
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///费用支付标志
	TThostFtdcFeePayFlagType	FeePayFlag;
	///应收客户费用
	TThostFtdcCustFeeType	CustFee;
	///应收期货公司费用
	TThostFtdcFutureFeeType	BrokerFee;
	///发送方给接收方的消息
	TThostFtdcAddInfoType	Message;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///转账交易状态
	TThostFtdcTransferStatusType	TransferStatus;
};

///冲正响应
struct CThostFtdcRspRepealField
{
	///冲正时间间隔
	TThostFtdcRepealTimeIntervalType	RepealTimeInterval;
	///已经冲正次数
	TThostFtdcRepealedTimesType	RepealedTimes;
	///银行冲正标志
	TThostFtdcBankRepealFlagType	BankRepealFlag;
	///期商冲正标志
	TThostFtdcBrokerRepealFlagType	BrokerRepealFlag;
	///被冲正平台流水号
	TThostFtdcPlateSerialType	PlateRepealSerial;
	///被冲正银行流水号
	TThostFtdcBankSerialType	BankRepealSerial;
	///被冲正期货流水号
	TThostFtdcFutureSerialType	FutureRepealSerial;
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///期货公司流水号
	TThostFtdcFutureSerialType	FutureSerial;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///转帐金额
	TThostFtdcTradeAmountType	TradeAmount;
	///期货可取金额
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///费用支付标志
	TThostFtdcFeePayFlagType	FeePayFlag;
	///应收客户费用
	TThostFtdcCustFeeType	CustFee;
	///应收期货公司费用
	TThostFtdcFutureFeeType	BrokerFee;
	///发送方给接收方的消息
	TThostFtdcAddInfoType	Message;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///转账交易状态
	TThostFtdcTransferStatusType	TransferStatus;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///查询账户信息请求
struct CThostFtdcReqQueryAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///期货公司流水号
	TThostFtdcFutureSerialType	FutureSerial;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
};

///查询账户信息响应
struct CThostFtdcRspQueryAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///期货公司流水号
	TThostFtdcFutureSerialType	FutureSerial;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///银行可用金额
	TThostFtdcTradeAmountType	BankUseAmount;
	///银行可取金额
	TThostFtdcTradeAmountType	BankFetchAmount;
};

///期商签到签退
struct CThostFtdcFutureSignIOField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
};

///期商签到响应
struct CThostFtdcRspFutureSignInField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///PIN密钥
	TThostFtdcPasswordKeyType	PinKey;
	///MAC密钥
	TThostFtdcPasswordKeyType	MacKey;
};

///期商签退请求
struct CThostFtdcReqFutureSignOutField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
};

///期商签退响应
struct CThostFtdcRspFutureSignOutField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///交易核心向银期报盘发出密钥同步请求
struct CThostFtdcReqSyncKeyField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///交易核心给银期报盘的消息
	TThostFtdcAddInfoType	Message;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
};

///交易核心向银期报盘发出密钥同步响应
struct CThostFtdcRspSyncKeyField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///交易核心给银期报盘的消息
	TThostFtdcAddInfoType	Message;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///查询账户信息通知
struct CThostFtdcNotifyQueryAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///期货公司流水号
	TThostFtdcFutureSerialType	FutureSerial;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///银行可用金额
	TThostFtdcTradeAmountType	BankUseAmount;
	///银行可取金额
	TThostFtdcTradeAmountType	BankFetchAmount;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///银期转账交易流水表
struct CThostFtdcTransferSerialField
{
	///平台流水号
	TThostFtdcPlateSerialType	PlateSerial;
	///交易发起方日期
	TThostFtdcTradeDateType	TradeDate;
	///交易日期
	TThostFtdcDateType	TradingDay;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///交易代码
	TThostFtdcTradeCodeType	TradeCode;
	///会话编号
	TThostFtdcSessionIDType	SessionID;
	///银行编码
	TThostFtdcBankIDType	BankID;
	///银行分支机构编码
	TThostFtdcBankBrchIDType	BankBranchID;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///期货公司编码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///期货公司帐号类型
	TThostFtdcFutureAccTypeType	FutureAccType;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///期货公司流水号
	TThostFtdcFutureSerialType	FutureSerial;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易金额
	TThostFtdcTradeAmountType	TradeAmount;
	///应收客户费用
	TThostFtdcCustFeeType	CustFee;
	///应收期货公司费用
	TThostFtdcFutureFeeType	BrokerFee;
	///有效标志
	TThostFtdcAvailabilityFlagType	AvailabilityFlag;
	///操作员
	TThostFtdcOperatorCodeType	OperatorCode;
	///新银行帐号
	TThostFtdcBankAccountType	BankNewAccount;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///请求查询转帐流水
struct CThostFtdcQryTransferSerialField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///银行编码
	TThostFtdcBankIDType	BankID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///期商签到通知
struct CThostFtdcNotifyFutureSignInField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///PIN密钥
	TThostFtdcPasswordKeyType	PinKey;
	///MAC密钥
	TThostFtdcPasswordKeyType	MacKey;
};

///期商签退通知
struct CThostFtdcNotifyFutureSignOutField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///交易核心向银期报盘发出密钥同步处理结果的通知
struct CThostFtdcNotifySyncKeyField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///交易核心给银期报盘的消息
	TThostFtdcAddInfoType	Message;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///交易ID
	TThostFtdcTIDType	TID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///请求查询银期签约关系
struct CThostFtdcQryAccountregisterField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///银行编码
	TThostFtdcBankIDType	BankID;
	///银行分支机构编码
	TThostFtdcBankBrchIDType	BankBranchID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///客户开销户信息表
struct CThostFtdcAccountregisterField
{
	///交易日期
	TThostFtdcTradeDateType	TradeDay;
	///银行编码
	TThostFtdcBankIDType	BankID;
	///银行分支机构编码
	TThostFtdcBankBrchIDType	BankBranchID;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///期货公司编码
	TThostFtdcBrokerIDType	BrokerID;
	///期货公司分支机构编码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///开销户类别
	TThostFtdcOpenOrDestroyType	OpenOrDestroy;
	///签约日期
	TThostFtdcTradeDateType	RegDate;
	///解约日期
	TThostFtdcTradeDateType	OutDate;
	///交易ID
	TThostFtdcTIDType	TID;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
};

///银期开户信息
struct CThostFtdcOpenAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	TThostFtdcGenderType	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///汇钞标志
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///交易ID
	TThostFtdcTIDType	TID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///银期销户信息
struct CThostFtdcCancelAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	TThostFtdcGenderType	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///汇钞标志
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///交易ID
	TThostFtdcTIDType	TID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///银期变更银行账号信息
struct CThostFtdcChangeAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	TThostFtdcSerialType	PlateSerial;
	///最后分片标志
	TThostFtdcLastFragmentType	LastFragment;
	///会话号
	TThostFtdcSessionIDType	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	TThostFtdcIdCardTypeType	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	TThostFtdcGenderType	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	TThostFtdcCustTypeType	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///新银行帐号
	TThostFtdcBankAccountType	NewBankAccount;
	///新银行密码
	TThostFtdcPasswordType	NewBankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///银行帐号类型
	TThostFtdcBankAccTypeType	BankAccType;
	///安装编号
	TThostFtdcInstallIDType	InstallID;
	///验证客户证件号码标志
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///银行密码标志
	TThostFtdcPwdFlagType	BankPwdFlag;
	///期货资金密码核对标志
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///交易ID
	TThostFtdcTIDType	TID;
	///摘要
	TThostFtdcDigestType	Digest;
	///请求编号
	TThostFtdcRequestIDType	RequestID;
	///错误代码
	TThostFtdcErrorIDType	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///资金账号归属关系
struct CThostFtdcAccountOwnerShipField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///属主代码
	TThostFtdcInvestorIDType	AccountOwner;
	///资金账号属主类型
	TThostFtdcAccountOwnerModeType	AccountOwnerMode;
	///是否活跃
	TThostFtdcBoolType	IsActive;
};

///客户端认证码
struct CThostFtdcAuthenticationCodeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///认证码
	TThostFtdcAuthCodeType	AuthCode;
	///旧认证码
	TThostFtdcAuthCodeType	PreAuthCode;
};

///组织架构
struct CThostFtdcDepartmentField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///组织架构代码
	TThostFtdcInvestorIDType	DepartmentID;
	///组织架构名称
	TThostFtdcPartyNameType	DepartmentName;
};

///操作员组织架构关系
struct CThostFtdcDepartmentUserField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///投资者范围
	TThostFtdcDepartmentRangeType	InvestorRange;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///组织架构投资者对应关系扁平表
struct CThostFtdcInvestorDepartmentFlatField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///组织架构代码
	TThostFtdcInvestorIDType	DepartmentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///交易系统参数
struct CThostFtdcTradeParamField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///参数代码
	TThostFtdcTradeParamIDType	TradeParamID;
	///参数代码值
	TThostFtdcSettlementParamValueType	TradeParamValue;
	///备注
	TThostFtdcMemoType	Memo;
};

///应用程序信息
struct CThostFtdcAppInfoField
{
	///应用名称
	TThostFtdcAppNameType	AppName;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///应用程序类型
	TThostFtdcAppTypeType	AppType;
};

///应用程序用户
struct CThostFtdcAppUserField
{
	///应用名称
	TThostFtdcAppNameType	AppName;
	///运行编号
	TThostFtdcRunIDType	RunID;
	///密码
	TThostFtdcPasswordType	Password;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
};

///交易中心
struct CThostFtdcDRIdentityField
{
	///交易中心代码
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///交易中心名称
	TThostFtdcDRIdentityNameType	DRIdentityName;
	///是否主中心
	TThostFtdcBoolType	IsMain;
};

///当前中心标识号
struct CThostFtdcCurrDRIdentityField
{
	///交易中心代码
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

///灾备中心交易权限
struct CThostFtdcUserRightAssignField
{
	///应用单元代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///交易中心代码
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

///经纪公司是否有在本标示的交易权限
struct CThostFtdcBrokerRightAssignField
{
	///应用单元代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易中心代码
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///能否交易
	TThostFtdcBoolType	Tradeable;
};

///Fens用户信息
struct CThostFtdcFensUserInfoField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///登录模式
	TThostFtdcLoginModeType	LoginMode;
};

///禁止登录用户
struct CThostFtdcLoginForbiddenUserField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
};

///查询禁止登录用户
struct CThostFtdcQryLoginForbiddenUserField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///UDP组播组信息
struct CThostFtdcMulticastGroupInfoField
{
	///组播组IP地址
	TThostFtdcIPAddressType	GroupIP;
	///组播组IP端口
	TThostFtdcIPPortType	GroupPort;
	///源地址
	TThostFtdcIPAddressType	SourceIP;
};

///资金账户基本准备金
struct CThostFtdcTradingAccountReserveField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///基本准备金
	TThostFtdcMoneyType	Reserve;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///查询基币种账户
struct CThostFtdcQryBaseCurrencyAccountField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///资金账户代码
	TThostFtdcAccountIDType	AccountID;
};

///基币种账户
struct CThostFtdcBaseCurrencyAccountField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///资金账户代码
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///查询持仓限额
struct CThostFtdcQryInvestorPositionLimitField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///持仓限额
struct CThostFtdcInvestorPositionLimitField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///品种代码
	TThostFtdcProductIDType	ProductID;
	///单笔报单最大手数
	TThostFtdcVolumeType	SingleOrderMaxVolume;
	///持仓限额
	TThostFtdcVolumeType	PositionLimit;
};

///行情最优买价属性
struct CThostFtdcMarketDataBestBidPriceField
{
	///申买价一
	TThostFtdcInt64PriceType	BidPrice1;
	///申买量一
	TThostFtdcVolumeType	BidVolume1;
};

///行情最优卖价属性
struct CThostFtdcMarketDataBestAskPriceField
{
	///申卖价一
	TThostFtdcInt64PriceType	AskPrice1;
	///申卖量一
	TThostFtdcVolumeType	AskVolume1;
};

///行情申买二属性
struct CThostFtdcMarketDataBid2Field
{
	///申买价二
	TThostFtdcInt64PriceType	BidPrice2;
	///申买量二
	TThostFtdcVolumeType	BidVolume2;
};

///行情申卖二属性
struct CThostFtdcMarketDataAsk2Field
{
	///申卖价二
	TThostFtdcInt64PriceType	AskPrice2;
	///申卖量二
	TThostFtdcVolumeType	AskVolume2;
};

///行情申买三属性
struct CThostFtdcMarketDataBid3Field
{
	///申买价三
	TThostFtdcInt64PriceType	BidPrice3;
	///申买量三
	TThostFtdcVolumeType	BidVolume3;
};

///行情申卖三属性
struct CThostFtdcMarketDataAsk3Field
{
	///申卖价三
	TThostFtdcInt64PriceType	AskPrice3;
	///申卖量三
	TThostFtdcVolumeType	AskVolume3;
};

///行情申买四属性
struct CThostFtdcMarketDataBid4Field
{
	///申买价四
	TThostFtdcInt64PriceType	BidPrice4;
	///申买量四
	TThostFtdcVolumeType	BidVolume4;
};

///行情申卖四属性
struct CThostFtdcMarketDataAsk4Field
{
	///申卖价四
	TThostFtdcInt64PriceType	AskPrice4;
	///申卖量四
	TThostFtdcVolumeType	AskVolume4;
};

///行情申买五属性
struct CThostFtdcMarketDataBid5Field
{
	///申买价五
	TThostFtdcInt64PriceType	BidPrice5;
	///申买量五
	TThostFtdcVolumeType	BidVolume5;
};

///行情申卖五属性
struct CThostFtdcMarketDataAsk5Field
{
	///申卖价五
	TThostFtdcInt64PriceType	AskPrice5;
	///申卖量五
	TThostFtdcVolumeType	AskVolume5;
};

///行情申买六属性
struct CThostFtdcMarketDataBid6Field
{
	///申买价六
	TThostFtdcInt64PriceType	BidPrice6;
	///申买量六
	TThostFtdcVolumeType	BidVolume6;
};

///行情申卖六属性
struct CThostFtdcMarketDataAsk6Field
{
	///申卖价六
	TThostFtdcInt64PriceType	AskPrice6;
	///申卖量六
	TThostFtdcVolumeType	AskVolume6;
};

///行情申买七属性
struct CThostFtdcMarketDataBid7Field
{
	///申买价七
	TThostFtdcInt64PriceType	BidPrice7;
	///申买量七
	TThostFtdcVolumeType	BidVolume7;
};

///行情申卖七属性
struct CThostFtdcMarketDataAsk7Field
{
	///申卖价七
	TThostFtdcInt64PriceType	AskPrice7;
	///申卖量七
	TThostFtdcVolumeType	AskVolume7;
};

///行情申买八属性
struct CThostFtdcMarketDataBid8Field
{
	///申买价八
	TThostFtdcInt64PriceType	BidPrice8;
	///申买量八
	TThostFtdcVolumeType	BidVolume8;
};

///行情申卖八属性
struct CThostFtdcMarketDataAsk8Field
{
	///申卖价八
	TThostFtdcInt64PriceType	AskPrice8;
	///申卖量八
	TThostFtdcVolumeType	AskVolume8;
};

///行情申买九属性
struct CThostFtdcMarketDataBid9Field
{
	///申买价九
	TThostFtdcInt64PriceType	BidPrice9;
	///申买量九
	TThostFtdcVolumeType	BidVolume9;
};

///行情申卖九属性
struct CThostFtdcMarketDataAsk9Field
{
	///申卖价九
	TThostFtdcInt64PriceType	AskPrice9;
	///申卖量九
	TThostFtdcVolumeType	AskVolume9;
};

///行情申买十属性
struct CThostFtdcMarketDataBid10Field
{
	///申卖价十
	TThostFtdcInt64PriceType	BidPrice10;
	///申卖量十
	TThostFtdcVolumeType	BidVolume10;
};

///行情申卖十属性
struct CThostFtdcMarketDataAsk10Field
{
	///申买价十
	TThostFtdcInt64PriceType	AskPrice10;
	///申买量十
	TThostFtdcVolumeType	AskVolume10;
};

///隐藏行情申买一属性
struct CThostFtdcMarketDataImplBid1Field
{
	///隐藏行情申买价一
	TThostFtdcInt64PriceType	ImplBidPrice1;
	///隐藏行情申买量一
	TThostFtdcVolumeType	ImplBidVolume1;
};

///隐藏行情申卖一属性
struct CThostFtdcMarketDataImplAsk1Field
{
	///隐藏行情申卖价一
	TThostFtdcInt64PriceType	ImplAskPrice1;
	///隐藏行情申卖量一
	TThostFtdcVolumeType	ImplAskVolume1;
};

///隐藏行情申买二属性
struct CThostFtdcMarketDataImplBid2Field
{
	///隐藏行情申买价二
	TThostFtdcInt64PriceType	ImplBidPrice2;
	///隐藏行情申买量二
	TThostFtdcVolumeType	ImplBidVolume2;
};

///隐藏行情申卖二属性
struct CThostFtdcMarketDataImplAsk2Field
{
	///隐藏行情申卖价二
	TThostFtdcInt64PriceType	ImplAskPrice2;
	///隐藏行情申卖量二
	TThostFtdcVolumeType	ImplAskVolume2;
};

///行情因子
struct CThostFtdcMarketDataFactorField
{
	///展示因子
	TThostFtdcDisplayFactorType	DisplayFactor;
	///转换因子
	TThostFtdcSwitchFactorType	SwitchFactor;
	///
	TThostFtdcBookDepthType	bookDepth;
	///
	TThostFtdcImpliedDepthType	impliedDepth;
};

///完整深度行情
struct CThostFtdcCmplDepthMarketDataField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///最新价
	TThostFtdcInt64PriceType	LastPrice;
	///上次结算价
	TThostFtdcInt64PriceType	PreSettlementPrice;
	///昨收盘
	TThostFtdcInt64PriceType	PreClosePrice;
	///昨持仓量
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///今开盘
	TThostFtdcInt64PriceType	OpenPrice;
	///最高价
	TThostFtdcInt64PriceType	HighestPrice;
	///最低价
	TThostFtdcInt64PriceType	LowestPrice;
	///数量
	TThostFtdcVolumeType	Volume;
	///成交金额
	TThostFtdcMoneyType	Turnover;
	///持仓量
	TThostFtdcLargeVolumeType	OpenInterest;
	///今收盘
	TThostFtdcInt64PriceType	ClosePrice;
	///本次结算价
	TThostFtdcInt64PriceType	SettlementPrice;
	///涨停板价
	TThostFtdcInt64PriceType	UpperLimitPrice;
	///跌停板价
	TThostFtdcInt64PriceType	LowerLimitPrice;
	///昨虚实度
	TThostFtdcRatioType	PreDelta;
	///今虚实度
	TThostFtdcRatioType	CurrDelta;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TThostFtdcMillisecType	UpdateMillisec;
	///申买价一
	TThostFtdcInt64PriceType	BidPrice1;
	///申买量一
	TThostFtdcVolumeType	BidVolume1;
	///申卖价一
	TThostFtdcInt64PriceType	AskPrice1;
	///申卖量一
	TThostFtdcVolumeType	AskVolume1;
	///申买价二
	TThostFtdcInt64PriceType	BidPrice2;
	///申买量二
	TThostFtdcVolumeType	BidVolume2;
	///申卖价二
	TThostFtdcInt64PriceType	AskPrice2;
	///申卖量二
	TThostFtdcVolumeType	AskVolume2;
	///申买价三
	TThostFtdcInt64PriceType	BidPrice3;
	///申买量三
	TThostFtdcVolumeType	BidVolume3;
	///申卖价三
	TThostFtdcInt64PriceType	AskPrice3;
	///申卖量三
	TThostFtdcVolumeType	AskVolume3;
	///申买价四
	TThostFtdcInt64PriceType	BidPrice4;
	///申买量四
	TThostFtdcVolumeType	BidVolume4;
	///申卖价四
	TThostFtdcInt64PriceType	AskPrice4;
	///申卖量四
	TThostFtdcVolumeType	AskVolume4;
	///申买价五
	TThostFtdcInt64PriceType	BidPrice5;
	///申买量五
	TThostFtdcVolumeType	BidVolume5;
	///申卖价五
	TThostFtdcInt64PriceType	AskPrice5;
	///申卖量五
	TThostFtdcVolumeType	AskVolume5;
	///当日均价
	TThostFtdcInt64PriceType	AveragePrice;
	///业务日期
	TThostFtdcDateType	ActionDay;
	///申买价六
	TThostFtdcInt64PriceType	BidPrice6;
	///申买量六
	TThostFtdcVolumeType	BidVolume6;
	///申卖价六
	TThostFtdcInt64PriceType	AskPrice6;
	///申卖量六
	TThostFtdcVolumeType	AskVolume6;
	///申买价七
	TThostFtdcInt64PriceType	BidPrice7;
	///申买量七
	TThostFtdcVolumeType	BidVolume7;
	///申卖价七
	TThostFtdcInt64PriceType	AskPrice7;
	///申卖量七
	TThostFtdcVolumeType	AskVolume7;
	///申买价八
	TThostFtdcInt64PriceType	BidPrice8;
	///申买量八
	TThostFtdcVolumeType	BidVolume8;
	///申卖价八
	TThostFtdcInt64PriceType	AskPrice8;
	///申卖量八
	TThostFtdcVolumeType	AskVolume8;
	///申买价九
	TThostFtdcInt64PriceType	BidPrice9;
	///申买量九
	TThostFtdcVolumeType	BidVolume9;
	///申卖价九
	TThostFtdcInt64PriceType	AskPrice9;
	///申卖量九
	TThostFtdcVolumeType	AskVolume9;
	///申买价十
	TThostFtdcInt64PriceType	BidPrice10;
	///申买量十
	TThostFtdcVolumeType	BidVolume10;
	///申卖价十
	TThostFtdcInt64PriceType	AskPrice10;
	///申卖量十
	TThostFtdcVolumeType	AskVolume10;
	///隐藏行情申买价一
	TThostFtdcInt64PriceType	ImplBidPrice1;
	///隐藏行情申买量一
	TThostFtdcVolumeType	ImplBidVolume1;
	///隐藏行情申卖价一
	TThostFtdcInt64PriceType	ImplAskPrice1;
	///隐藏行情申卖量一
	TThostFtdcVolumeType	ImplAskVolume1;
	///隐藏行情申买价二
	TThostFtdcInt64PriceType	ImplBidPrice2;
	///隐藏行情申买量二
	TThostFtdcVolumeType	ImplBidVolume2;
	///隐藏行情申卖价二
	TThostFtdcInt64PriceType	ImplAskPrice2;
	///隐藏行情申卖量二
	TThostFtdcVolumeType	ImplAskVolume2;
	///展示因子
	TThostFtdcDisplayFactorType	DisplayFactor;
	///转换因子
	TThostFtdcSwitchFactorType	SwitchFactor;
	///档位深度
	TThostFtdcBookDepthType	bookDepth;
	///隐藏档位深度
	TThostFtdcImpliedDepthType	impliedDepth;
	///行情报文序号
	TThostFtdcSequenceNumType	MDSequenceNum;
	///交易所行情报文序号
	TThostFtdcSequenceNumType	RptSeq;
};


}
#endif
