#ifndef FDRIVER_CAPABILITIES_H
#define FDRIVER_CAPABILITIES_H

#include "conversions.h"
#include "detail/picojson.h"
#include <string>

namespace fdriver {

namespace browser {
typedef std::string Value;
typedef const char* const ConstValue;
ConstValue Android = "android";
ConstValue Chrome = "chrome";
ConstValue Firefox = "firefox";
ConstValue HtmlUnit = "htmlunit";
ConstValue InternetExplorer = "internet explorer";
ConstValue IPhone = "iPhone";
ConstValue IPad = "iPad";
ConstValue Mock = "mock";
ConstValue Opera = "opera";
ConstValue Safari = "safari";
ConstValue Phantom = "phantomjs";
} // namespace browser

namespace platform {
typedef std::string Value;
typedef const char* const ConstValue;
ConstValue Any = "ANY";
ConstValue Windows = "WINDOWS";
ConstValue Xp = "XP";
ConstValue Vista = "VISTA";
ConstValue Mac = "MAC";
ConstValue Linux = "LINUX";
ConstValue Unix = "UNIX";
ConstValue Android = "ANDROID";
} // namespace platform

namespace unexpected_alert_behaviour {
typedef std::string Value;
typedef const char* const ConstValue;
ConstValue Accept = "accept";
ConstValue Dismiss = "dismiss";
ConstValue Ignore = "ignore";
} // namespace unexpected_alert_behaviour

namespace proxy_type {
typedef std::string Value;
typedef const char* const ConstValue;
ConstValue Direct = "direct";
ConstValue Manual = "manual"; // Manual proxy settings configured, e.g. setting a proxy for HTTP, a proxy for FTP
ConstValue Pac = "pac"; // Proxy autoconfiguration from a URL
ConstValue Autodetect = "autodetect"; // Proxy autodetection, probably with WPAD
ConstValue System = "system"; // Use system settings
} // namespace proxy_type

#define FDRIVER_PROPERTIES_BEGIN(this_class)	typedef this_class This;
#define FDRIVER_PROPERTIES_END()

#define FDRIVER_PROPERTY_RONLY(name, id, type) \
	type Get##name() const { return GetOptional<type>(id); } \
	bool Has##name() { return Has(id); }

#define FDRIVER_PROPERTY(name, id, type) \
	FDRIVER_PROPERTY_RONLY(name, id, type) \
	This& Set##name(const type& value) { Set(id, value); return *this; }

struct Proxy : JsonObject { // copyable
	FDRIVER_PROPERTIES_BEGIN(Proxy)
	FDRIVER_PROPERTY(ProxyType, "proxyType", proxy_type::Value)
	FDRIVER_PROPERTIES_END()
};

struct DirectConnection : Proxy { // copyable
	DirectConnection() { SetProxyType(proxy_type::Direct); }
};

struct AutodetectProxy : Proxy { // copyable
	AutodetectProxy() { SetProxyType(proxy_type::Autodetect); }
};

struct SystemProxy : Proxy { // copyable
	SystemProxy() { SetProxyType(proxy_type::System); }
};

struct AutomaticProxyFromUrl : Proxy { // copyable
	explicit AutomaticProxyFromUrl(const std::string& url) {
		SetProxyType(proxy_type::Pac);
		SetAutoconfigUrl(url);
	}

	FDRIVER_PROPERTIES_BEGIN(AutomaticProxyFromUrl)
	FDRIVER_PROPERTY(AutoconfigUrl, "proxyAutoconfigUrl", std::string)
	FDRIVER_PROPERTIES_END()
};

struct ManualProxy : Proxy { // copyable
	ManualProxy() { SetProxyType(proxy_type::Manual); }

	FDRIVER_PROPERTIES_BEGIN(ManualProxy)
	FDRIVER_PROPERTY(NoProxyFor, "noProxy", std::string)
	FDRIVER_PROPERTIES_END()
};

struct FtpProxy : ManualProxy { // copyable
	explicit FtpProxy(const std::string& address) { SetProxyAddress(address); }

	FDRIVER_PROPERTIES_BEGIN(FtpProxy)
	FDRIVER_PROPERTY(ProxyAddress, "ftpProxy", std::string)
	FDRIVER_PROPERTIES_END()
};

struct HttpProxy : ManualProxy { // copyable
	explicit HttpProxy(const std::string& address) { SetProxyAddress(address); }

	FDRIVER_PROPERTIES_BEGIN(HttpProxy)
	FDRIVER_PROPERTY(ProxyAddress, "httpProxy", std::string)
	FDRIVER_PROPERTIES_END()
};

struct SslProxy : ManualProxy { // copyable
	explicit SslProxy(const std::string& address) { SetProxyAddress(address); }

	FDRIVER_PROPERTIES_BEGIN(SslProxy)
	FDRIVER_PROPERTY(ProxyAddress, "sslProxy", std::string)
	FDRIVER_PROPERTIES_END()
};

struct SocksProxy : ManualProxy { // copyable
	explicit SocksProxy(const std::string& address) { SetProxyAddress(address); }

	FDRIVER_PROPERTIES_BEGIN(SocksProxy)
	FDRIVER_PROPERTY(ProxyAddress, "socksProxy", std::string)
	FDRIVER_PROPERTY(Username, "socksUsername", std::string)
	FDRIVER_PROPERTY(Password, "socksPassword", std::string)
	FDRIVER_PROPERTIES_END()
};

namespace log_level {
typedef std::string Value;
typedef const char* const ConstValue;
ConstValue Off = "OFF";
ConstValue Severe = "SEVERE";
ConstValue Warning = "WARNING";
ConstValue Info = "INFO";
ConstValue Config = "CONFIG";
ConstValue Fine = "FINE";
ConstValue Finer = "FINER";
ConstValue Finest = "FINEST";
ConstValue All = "ALL";
} // namespace log_level

struct LoggingPrefs : JsonObject {
	FDRIVER_PROPERTIES_BEGIN(LoggingPrefs)
	FDRIVER_PROPERTY(Level, "driver", log_level::Value)
	FDRIVER_PROPERTIES_END()
};

// List of keys and values indicating features that server can or should provide.
struct Capabilities : JsonObject { // copyable
	Capabilities() {}
	explicit Capabilities(const picojson::object& object) : JsonObject(object) {}

	// Hardcoded capabilities are here just to add some sugar.
	// If a capability is not listed below use Get/Set/Has public members.

	FDRIVER_PROPERTIES_BEGIN(Capabilities)
	FDRIVER_PROPERTY(BrowserName, "browserName", browser::Value)
	FDRIVER_PROPERTY(Version, "version", std::string)
	FDRIVER_PROPERTY(Platform, "platform", platform::Value)

	FDRIVER_PROPERTY_RONLY(TakesScreenshot, "takesScreenshot", bool)
	FDRIVER_PROPERTY_RONLY(HandlesAlerts, "handlesAlerts", bool)
	FDRIVER_PROPERTY_RONLY(CssSelectorsEnabled, "cssSelectorsEnabled", bool)

	FDRIVER_PROPERTY(JavascriptEnabled, "javascriptEnabled", bool)
	FDRIVER_PROPERTY(DatabaseEnabled, "databaseEnabled", bool)
	FDRIVER_PROPERTY(LocationContextEnabled, "locationContextEnabled", bool)
	FDRIVER_PROPERTY(ApplicationCacheEnabled, "applicationCacheEnabled", bool)
	FDRIVER_PROPERTY(BrowserConnectionEnabled, "browserConnectionEnabled", bool)
	FDRIVER_PROPERTY(WebStorageEnabled, "webStorageEnabled", bool)
	FDRIVER_PROPERTY(AcceptSslCerts, "acceptSslCerts", bool)
	FDRIVER_PROPERTY(Rotatable, "rotatable", bool)
	FDRIVER_PROPERTY(NativeEvents, "nativeEvents", bool)
	FDRIVER_PROPERTY(Proxy, "proxy", Proxy)
	FDRIVER_PROPERTY(UnexpectedAlertBehaviour, "unexpectedAlertBehaviour", unexpected_alert_behaviour::Value)
	FDRIVER_PROPERTY(ElementScrollBehavior, "elementScrollBehavior", int)

	FDRIVER_PROPERTY_RONLY(SessionId, "webdriver.remote.sessionid", std::string)
	FDRIVER_PROPERTY(QuietExceptions, "webdriver.remote.quietExceptions", bool)
	FDRIVER_PROPERTIES_END()
};

inline
void CustomFromJson(const picojson::value& value, Capabilities& result) {
	FDRIVER_CHECK(value.is<picojson::object>(), "Capabilities is not an object");
	result = Capabilities(value.get<picojson::object>());
}

} // namespace fdriver

#endif
