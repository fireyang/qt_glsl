#ifndef TESTCURL_H
#define TESTCURL_H
#include "curl/curl.h"
#include "zlib.h"

#include <ft2build.h>
#include FT_RENDER_H

void testCurl(){
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
     fprintf(stdout,"ttttt");
    if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
      /* example.com is redirected, so we tell libcurl to follow redirection */
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

      /* Perform the request, res will get the return code */
      res = curl_easy_perform(curl);
      /* Check for errors */
      if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
      fprintf(stdout,"ttttt");

      /* always cleanup */
      curl_easy_cleanup(curl);
    }
}

void testZlib(){
    const unsigned char strSrc[]="hello world!";
    unsigned char buff[1024]={0};
    unsigned long bufLen = sizeof(buff),srcLen = sizeof(strSrc);
    compress(buff,&bufLen,strSrc,srcLen);
}

void testFT(){
    FT_Library library;
    int error;
    error = FT_Init_FreeType(&library);
    if(error){

    }
}

#endif // TESTCURL_H
