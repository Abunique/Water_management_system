#include <pgmspace.h>
#define THINGNAME "esp32_mqtt_test"    

                     //change this
 
const char WIFI_SSID[] = "Srushty Global Solutions";               //change this
const char WIFI_PASSWORD[] = "srushty!@#$%";           //change this
const char AWS_IOT_ENDPOINT[] = "http://103.108.117.101:7000/v1/device/createDeviceData";       //change this
 

// amazon ca certificate
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
 )EOF";

// Device Certificate                                               //change this

static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAJ9xPkDh92Ccjj1op1WQLrSseAgLMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzEyMjEwNjQ3
NDdaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCattTvQ+qNTg3kCjWT
7B8yzNvU82iKa/WMb2UEUXuPsyb/sO7gyLprihmWlWwoD2ckn6kTGOXAffouwyEB
0NgsPpZe5X/2WuxrtDWJA2OzX+8T6GkTCUmYVAvMIs3ET54l6fW+Rm79Ermz1pMM
HGiEiRsiUnre8Z6aZVKWLsZUbC4eGw4gPF/AFwJ3tY+9AwDg+f4n9REU2AC2Uir1
XHWF3IsSlFBVeVywZA122GEJr9m4wnsDFz1Q7DiejC3rKQorOwovJdCtyZexBwFA
+J7/WgSa3/AD8WlhqFxqtdoLRn+wUN+8TgMG82zOGE/tMxvkjzeLn6FVjxQRkNDB
EskXAgMBAAGjYDBeMB8GA1UdIwQYMBaAFEPhLMXkApIYLxe+MkJnlDKzy/DFMB0G
A1UdDgQWBBQkyUm9dNBUFXu2dx028TwOOiEU7zAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAhYA+h9xlgqqsvkQ0M2V0+1os
cjdT8JJdfZOcTpD4WLcnrmQA7yVt06yWyrjnzzKiUdNkl/zwlVZyQ8Hg1umpuHnm
eWLiGve01PKlg0Kt9DehesiBQHjo2OSIlzHNLdg3s5dHTjSLZPDPlgEKtIkdlbsn
fJ5BkidStGmbVFcDs5+7XDqHdoRXKu23PhZXl9BK7MvhQ4LA0loohSgVtbuBqtb3
E/FCocDccPt2kocX5TjbYgOwlZ6K+0M2hUd/Kvboz+wdD5wwSAgH9KkgPGSmMzqz
8Chabb6CYk+JyUqkPnskunSnajWK5ppAIb5uK9l/FED1h/bBa6FtrYUIQjUWGQ==
-----END CERTIFICATE-----

)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAmrbU70PqjU4N5Ao1k+wfMszb1PNoimv1jG9lBFF7j7Mm/7Du
4Mi6a4oZlpVsKA9nJJ+pExjlwH36LsMhAdDYLD6WXuV/9lrsa7Q1iQNjs1/vE+hp
EwlJmFQLzCLNxE+eJen1vkZu/RK5s9aTDBxohIkbIlJ63vGemmVSli7GVGwuHhsO
IDxfwBcCd7WPvQMA4Pn+J/URFNgAtlIq9Vx1hdyLEpRQVXlcsGQNdthhCa/ZuMJ7
Axc9UOw4nowt6ykKKzsKLyXQrcmXsQcBQPie/1oEmt/wA/FpYahcarXaC0Z/sFDf
vE4DBvNszhhP7TMb5I83i5+hVY8UEZDQwRLJFwIDAQABAoIBAG2YoISRruDEbzCg
Ts3nkT4yQnO6rc6IpZwC+SMy+X2VIkY0tzNC3lP5syCp3sEOEDmwZFvj4jUWyJhB
n+siX1AQUgMNPjVsuVeeg+H4JbNWfQy0MWLLzHd86hKEgRDUeapP7sYILO1XS3dq
xCXrJdrlKPSKSwINVRX4OqWqotH/6ji2ZGop8Ux1X1LXTkolS9bL+yJtTe4AmqTo
5vOnpXYhFZR2IayXyW4xqkj7RKVQg/XLA75v2cI+PNH5QHCSNtSjpvr8hKPcYzPc
nCx/TXwZBs69ZZPygMV3PjlBDE9pDKoWS8Wc+BejauwnFiBjNgUjzlKVmssQzEI7
OC5Hj+ECgYEAyi8d89Fl7Q4zcoSpfTxZWkFUjqITOwgLauQbWA1fKcNM5q3kkrHv
DU1vLrD82utOnuCxZwVDBYoIMJmskx3H0nA4Flue9pS9YZv/FdXFmNecEQMELO3a
PbbcNozmLdEnWvuynyZ7dxfpSrOTDkaX+MbVjqdsiA71hnjFebFPHWcCgYEAw+Ua
jcSovNk8LBzDwHyB2VUT50TEamBs9teG4uT/VehR33b09ISzsc+U5EXGRiIlKVFl
uBw50p9kXVWsdSKgdACWgsqOzNFAcpVWh+WH4LM6aL1ZTb8JSYWILNsV7rcwV4ve
MOc1gHda5GJ+JDla/MdqtZmCW9iK8atvdu0A+NECgYBr9frlfdQSYDnilao3YGlK
A4aWXz8rj2EhY8qiGwnMsCe5KfPazT6b+NQ8t29dqrahqdOw8iNWqt0yrmxzZjyU
Ry376lKY0tXJcFYmn67SrZb9koHBSAT4XVN7oYMrxfpg3/QCfbcB4ffF1tvYjKOL
yQiyEv6mLG64rnasQ5y+UwKBgQC76gMN6Y+AENdC7ZjuBcG9zHoaSIIuFS+RnnA7
KTaynvgi6AbUpJOHxzvpufEYB9skBnwQH6tsGxB45B1aBAxtGr9G2a4gVb5/7Dek
hw9QAj3OiYyoItBy4ZAej087vii2YmqS+Mf+4v+iw8SDVS2t/FGlwIsnNdMbPrvf
FjzvcQKBgQCYfe6LYMeEIwMrrS3B7zwWwK2aMGmmnOMxJpPUTQQp4F8K2Woc1JMN
4ReY8uEEhJufV17FacvRd8PfcefKA2FFrXtrILQOdaVRHC2+HqIMn5/1jFcZQWzq
b3+zroEAv0l6AlE9ddPN49eGuiLGcs8n6B888YtWXjka+lustBopJw==
-----END RSA PRIVATE KEY-----


)KEY";


