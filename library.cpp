// USING Wininet SYSTEM TO READ INFORMATIONS

HINTERNET user_agent = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
HINTERNET content_url;
string ret_network;
string replaceAll(string base, const string& search,
	const string& replace) {
	size_t pos = 0;
	while ((pos = base.find(search, pos)) != string::npos) {
		base.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return base;
}
string read_data(string URL) {
	if (user_agent) {
		content_url = InternetOpenUrlA(user_agent, URL.c_str(), NULL, NULL, NULL, NULL);
		if (content_url) {
			char buffer[2000];
			DWORD bytesRead;
			do {
				InternetReadFile(content_url, buffer, 2000, &bytesRead);
				ret_network.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(user_agent);
			InternetCloseHandle(content_url);
			string p = replaceAll(ret_network, "|n", "\r\n");
			return p;
		}
	}
	InternetCloseHandle(user_agent);
	string p = replaceAll(ret_network, "|n", "\r\n");
	return p;
}
