// Public
void requestAccessToken(char *authCode);
void getAccessTokenFromFile(char *accessToken);


// Private 
size_t saveRequestRespond(char *in, size_t nmem, size_t nitems, void* out);
void errorHandle(char *mes, CURLcode res);