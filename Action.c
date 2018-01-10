/*********************************************************************************************************
// This LoadRunner script is designed to log-into the myCWT Application, display the Home page, MyTrip and expand 
// view trip then logout. 
//
// Developed on 08/20/2017 By Prashant Bhutani 
//
// Update on 01/10/2018 By Amanuel Berhane
//
/*********************************************************************************************************/
Action()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.1");
	web_cleanup_cookies();
	web_cache_cleanup();
	web_set_max_html_param_len("99999");
	
//	web_add_cookie("JSESSIONID=1799059914EFAFAA797E989792478D6C; DOMAIN=test.mytravelsite.carlsonwagonlit.com");
 	web_add_cookie("COOKIE_SUPPORT=true; DOMAIN=test.mytravelsite.carlsonwagonlit.com");

	web_reg_save_param("SAMLRequest_SSO.saml2",
		"LB=<input type=\"hidden\" name=\"SAMLRequest\" value=\"",
		"RB=\"/>    ",
		"NotFound=ERROR",
		"Search=All",
		LAST);

    lr_start_transaction("Portal_001_IDM");
    
	web_url("test.mytravelsite.carlsonwagonlit.com",
		"URL=https://test.mytravelsite.carlsonwagonlit.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

    web_reg_save_param("IDP_Token",
		"LB=form method=\"POST\" action=\"/idp/",
		"RB=/resumeSAML20/idp/SSO",
		"NotFound=ERROR",
		"Search=All",
		LAST);
//
//	web_reg_find("Fail=NotFound",
//		"Search=Body",
//		"Text=Your gateway to business travel",
//		LAST);
    
	web_submit_data("SSO.saml2", 
		"Action=https://test.mytravel.carlsonwagonlit.com/idp/SSO.saml2", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://test.mytravelsite.carlsonwagonlit.com/c/portal/login?redirect=%2F&refererPlid=30692&p_l_id=20146", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=RelayState", "Value=/", ENDITEM, 
		"Name=SAMLRequest", "Value={SAMLRequest_SSO.saml2}", ENDITEM,
//		"PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiPz4KPHNhbWwycDpBdXRoblJlcXVlc3QgQXNzZXJ0aW9uQ29uc3VtZXJTZXJ2aWNlVVJMPSJodHRwczovL3Rlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20vYy9wb3J0YWwvc2FtbC9hY3MiIERlc3RpbmF0aW9uPSJodHRwczovL3Rlc3QubXl0cmF2ZWwuY2FybHNvbndhZ29ubGl0LmNvbS9pZHAvU1NPLnNhbWwyIiBGb3JjZUF1dGhuPSJmYWxzZSIgSUQ9Il85ODFlZWYxY2FlYTk2MTFmNzJkOTA5ODliYTQ3N2QyOTUyZTk5YzM0IiBJc1Bhc3NpdmU9ImZhbHNlIiBJc3N1ZUluc3RhbnQ9IjIwMTctMDgtMDNUMTk6MjE6MzYuNjAyWiIgUHJvdG9jb2xCaW5kaW5nPSJ1cm46b2FzaXM6bm"
//		"FtZXM6dGM6U0FNTDoyLjA6YmluZGluZ3M6SFRUUC1QT1NUIiBWZXJzaW9uPSIyLjAiIHhtbG5zOnNhbWwycD0idXJuOm9hc2lzOm5hbWVzOnRjOlNBTUw6Mi4wOnByb3RvY29sIj48c2FtbDI6SXNzdWVyIHhtbG5zOnNhbWwyPSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXNzZXJ0aW9uIj50ZXN0X2xpZmVyYXlfc2FtbF9zZXJ2aWNlX3Byb3ZpZGVyPC9zYW1sMjpJc3N1ZXI+PGRzOlNpZ25hdHVyZSB4bWxuczpkcz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC8wOS94bWxkc2lnIyI+PGRzOlNpZ25lZEluZm8+"
//		"PGRzOkNhbm9uaWNhbGl6YXRpb25NZXRob2QgQWxnb3JpdGhtPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzEwL3htbC1leGMtYzE0biMiLz48ZHM6U2lnbmF0dXJlTWV0aG9kIEFsZ29yaXRobT0iaHR0cDovL3d3dy53My5vcmcvMjAwMC8wOS94bWxkc2lnI3JzYS1zaGExIi8+PGRzOlJlZmVyZW5jZSBVUkk9IiNfOTgxZWVmMWNhZWE5NjExZjcyZDkwOTg5YmE0NzdkMjk1MmU5OWMzNCI+PGRzOlRyYW5zZm9ybXM+PGRzOlRyYW5zZm9ybSBBbGdvcml0aG09Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvMDkveG1sZHNpZyNlbnZlbG9wZWQtc2lnbmF0dXJlIi8+"
//		"PGRzOlRyYW5zZm9ybSBBbGdvcml0aG09Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvMTAveG1sLWV4Yy1jMTRuIyIvPjwvZHM6VHJhbnNmb3Jtcz48ZHM6RGlnZXN0TWV0aG9kIEFsZ29yaXRobT0iaHR0cDovL3d3dy53My5vcmcvMjAwMC8wOS94bWxkc2lnI3NoYTEiLz48ZHM6RGlnZXN0VmFsdWU+czQwZzZUZFdWYWdyc3NrclJuSHJFQjEvcjM4PTwvZHM6RGlnZXN0VmFsdWU+PC9kczpSZWZlcmVuY2U+"
//		"PC9kczpTaWduZWRJbmZvPjxkczpTaWduYXR1cmVWYWx1ZT5TNEludUFYdk9ReVBySkJ1QVZIenZhcGMwL3ltLzhaMUZjNDdtUVpDMjl1cjdUWEgvaDJsQ0xEUzVlV3RFbGlaRXhDWVd5dFhCVVNsVkk2NllQVWNTaDdBelp3eWhrd3F6ejEvdFA5c2dsbDV5dmluWXlTQlVRUTI4azRLaW5NSk1hZmhTMDFDV3oyVTJueDJnb2lyUWlvNk9ham1mODBPK01laXdyamRFMFRYYjkyTVlQbTkyVHEyS1NtMHBLMEpNeFBRVm1FWE5OOXo5dDlTYldqNXVjdDk4RGt3VUo3MkRoUzhuY1FTSDVIS0E0TTJ1WlpENzJJbjJuUVc0Qi9ycWNjYUphbnNHTVRUN1JLWDArMmRjb1Y5aU9zV1ZvdnptQTRvWnIvVGdmNmdsMzJDRHRFK3JOMmFia3huZlZ3ZDZRMy9rdzRsYkNZaTk4T0NpR2pPbF"
//		"E9PTwvZHM6U2lnbmF0dXJlVmFsdWU+PGRzOktleUluZm8+PGRzOlg1MDlEYXRhPjxkczpYNTA5Q2VydGlmaWNhdGU+"
//		"TUlJRExEQ0NBaFNnQXdJQkFnSUVXVkVIVWpBTkJna3Foa2lHOXcwQkFRVUZBREJZTVJBd0RnWURWUVFHRXdkVmJtdHViM2R1TVF3dwpDZ1lEVlFRSUV3TkRWMVF4RERBS0JnTlZCQWNUQTBOWFZERU1NQW9HQTFVRUNoTURRMWRVTVF3d0NnWURWUVFMRXdORFYxUXhEREFLCkJnTlZCQU1UQTBOWFZEQWVGdzB4TnpBMk1qWXhNekE0TXpSYUZ3MHhOekE1TWpReE16QTRNelJhTUZneEVEQU9CZ05WQkFZVEIxVnUKYTI1dmQyNHhEREFLQmdOVkJBZ1RBME5YVkRFTU1Bb0dBMVVFQnhNRFExZFVNUXd3Q2dZRFZRUUtFd05EVjFReEREQUtCZ05WQkFzVApBME5YVkRFTU1Bb0dBMVVFQXhNRFExZFVNSUlCSWpBTkJna3Foa2lHOXcwQkFRRUZBQU9DQVE4QU1JSUJDZ0tDQVFFQX"
//		"BZTXJ2dTB4CkRXODRGYUxQRnQ0S1o3WGxFV01yN2haTWk4aDVsT1ZEWU51Z0VmbzdqZCtzeVVlWEJCQ2Jvb0tnKzlHSDVHa3k2UUVkVlVpMVNhSDYKbXgraXpTNEFlS0grTzBPb3QxSDk0YlhBbTExSTEyYUZXSGRIdEF2UUVqQ080a0x2NXdlbExxSlViMm9iU0xkRWpZUnNoem1qOXppbgpyeDgzOExuWjZUNG14YmNIblNZc2JRcDREWFpoRUtsQVRoMzRhSHVkajAyOTdoajNnU3BFeDYvRDZlQ1VOdnlnVDZMZEJlUjFNRXZHCnZGVzRQazRidVlwejFLanoyMHh4SkE0UitPTjFZTXVtYlhSRlF4NGRoSVhoeTZnVUVwN0pxbE0yK25MVFRFbnFwOEVmWThHbzZoZjQKay9vNHhla2pNWUx4SDIzRzRhOGNNZ3paVGFleS9RSURBUUFCTUEwR0NTcUdTSWIzRFFFQkJRVUFBNElC"
//		"QVFCM0RDOVVad1dIalV3TgpTZDRPOEI4RFY4NS91Q0w1QytHcUhxa1pHYXhkK3JUdkNSdWRqT1FSTit6SkpGOXdod3BQNVlycVljTzVRdmVUTEFsK0NoSjlIK3J4CnpZbnQvNEhWd2pvb0ZZd1pLYkNKSXFrQU9Da1FkVmdOMVZ4ZlNZZnZkenh1N2MzekJWSng2VDJqaGNJbHRKS2tobzBvS3hKblBNdWUKdkorMDhDUFZEYi9uWXg1TzdQRDNNRVRSZHZNWFpTK3UxUUVkNTdhQkNxSnlJWUxCWGhidW90MThGTDdFQ0luWGltaDNkTEFRdlhVMwpSZENCR2I1OFEvOHNWZFRvc2hQWnIzVDBhbWtLMTlkbGtVOUdGR0RoKzk1Vzhxank0YUJaVmV4WlFENFgwMEd3NWNaMGMyZm5iazFGCjZXQ0NsalFEbDJrNDdsRmtEK3M3bDNySTwvZHM6WDUwOUNlcnRpZmljYXRlPjwvZHM6WD"
//		"UwOURhdGE+PC9kczpLZXlJbmZvPjwvZHM6U2lnbmF0dXJlPjxzYW1sMnA6TmFtZUlEUG9saWN5IEFsbG93Q3JlYXRlPSJ0cnVlIiBGb3JtYXQ9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjEuMTpuYW1laWQtZm9ybWF0OnVuc3BlY2lmaWVkIiB4bWxuczpzYW1sMnA9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjIuMDpwcm90b2NvbCIvPjwvc2FtbDJwOkF1dGhuUmVxdWVzdD4=", ENDITEM, 
		EXTRARES, 
		LAST);

	web_submit_data("ping", 
		"Action=https://api-iam.intercom.io/messenger/web/ping", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://test.mytravel.carlsonwagonlit.com/idp/SSO.saml2", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=app_id", "Value=lwx93sjz", ENDITEM, 
		"Name=v", "Value=3", ENDITEM, 
		"Name=g", "Value=d0294981254ef58e1591a551d99f33a86c193883", ENDITEM, 
		"Name=s", "Value=f5d51a05-24af-4695-b8a3-cb1cd5c89f70", ENDITEM, 
		"Name=i", "Value=", ENDITEM, 
		"Name=r", "Value=https://test.mytravelsite.carlsonwagonlit.com/c/portal/login?redirect=%2F&refererPlid=30692&p_l_id=20146", ENDITEM, 
		"Name=platform", "Value=web", ENDITEM, 
		"Name=Idempotency-Key", "Value=61981657", ENDITEM, 
		"Name=user_data", "Value={}", ENDITEM, 
		"Name=referer", "Value=https://test.mytravel.carlsonwagonlit.com/idp/SSO.saml2", ENDITEM, 
		EXTRARES, 
		LAST);

	lr_end_transaction("Portal_001_IDM",LR_AUTO);
	
	lr_think_time(1);

	lr_start_transaction("Portal_002_Login_&_HomePage");

	web_reg_save_param("SAMLResponse_acs",
		"LB=input type=\"hidden\" name=\"SAMLResponse\" value=\"",
		"RB=\"/>",
		"NotFound=ERROR",
		"Search=All",
		LAST);
	
		
	web_submit_data("SSO.ping", 
		"Action=https://test.mytravel.carlsonwagonlit.com/idp/{IDP_Token}/resumeSAML20/idp/SSO.ping", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://test.mytravel.carlsonwagonlit.com/idp/SSO.saml2", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=pf.username", "Value={UserID}", ENDITEM, 
		"Name=pf.pass", "Value=Qwerty10!", ENDITEM, 
		"Name=pf.ok", "Value=clicked", ENDITEM, 
		"Name=pf.cancel", "Value=", ENDITEM, 
		"Name=pf.adapterId", "Value=htmlForm2", ENDITEM, 
		LAST);


//	web_reg_find("Fail=NotFound",
//		"Search=Body",
//		"Text=Company News",
//		LAST);
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text/DIG=Home - Zundongreen-sub-#### - Zundongreen - myCWT",
		LAST);

	web_reg_save_param("sub_no",
		"LB=Home - Zundongreen-sub-",
		"RB= - Zundongreen - myCWT",
		"NotFound=ERROR",
		"Search=All",
		LAST);
	
	
	//Home - Zundongreen-sub-7984 - Zundongreen - myCWT
	
	//web_set_max_retries ("2");
	
	web_submit_data("acs", 
		"Action=https://test.mytravelsite.carlsonwagonlit.com/c/portal/saml/acs", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://test.mytravel.carlsonwagonlit.com/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=RelayState", "Value=/", ENDITEM, 
		"Name=SAMLResponse", "Value={SAMLResponse_acs}", ENDITEM,
////		"PHNhbWxwOlJlc3BvbnNlIFZlcnNpb249IjIuMCIgSUQ9IlFvZk83UHMweHFYVGJLc3JfLjlzRXZtUTFoTCIgSXNzdWVJbnN0YW50PSIyMDE3LTA4LTAzVDE5OjIyOjAyLjE2NVoiIEluUmVzcG9uc2VUbz0iXzk4MWVlZjFjYWVhOTYxMWY3MmQ5MDk4OWJhNDc3ZDI5NTJlOTljMzQiIERlc3RpbmF0aW9uPSJodHRwczovL3Rlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20vYy9wb3J0YWwvc2FtbC9hY3MiIHhtbG5zOnNhbWxwPSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6cHJvdG9jb2wiPjxzYW1sOklzc3VlciB4bWxuczpzYW1sPSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXNzZXJ0aW9uIj5wb3J0YWw6c3RhZ2U6Y3d0OnNhbWwyPC"
////		"9zYW1sOklzc3Vlcj48ZHM6U2lnbmF0dXJlIHhtbG5zOmRzPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwLzA5L3htbGRzaWcjIj4KPGRzOlNpZ25lZEluZm8+CjxkczpDYW5vbmljYWxpemF0aW9uTWV0aG9kIEFsZ29yaXRobT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS8xMC94bWwtZXhjLWMxNG4jIi8+CjxkczpTaWduYXR1cmVNZXRob2QgQWxnb3JpdGhtPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNyc2Etc2hhMjU2Ii8+CjxkczpSZWZlcmVuY2UgVVJJPSIjUW9mTzdQczB4cVhUYktzcl8uOXNFdm1RMWhMIj4KPGRzOlRyYW5zZm9ybXM+"
////		"CjxkczpUcmFuc2Zvcm0gQWxnb3JpdGhtPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwLzA5L3htbGRzaWcjZW52ZWxvcGVkLXNpZ25hdHVyZSIvPgo8ZHM6VHJhbnNmb3JtIEFsZ29yaXRobT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS8xMC94bWwtZXhjLWMxNG4jIi8+CjwvZHM6VHJhbnNmb3Jtcz4KPGRzOkRpZ2VzdE1ldGhvZCBBbGdvcml0aG09Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvMDQveG1sZW5jI3NoYTI1NiIvPgo8ZHM6RGlnZXN0VmFsdWU+aVVTa2pnd2NBeVFiMW45czM4b3E0STRZbHcyM0swWnlMZEREK0RteW9oVT08L2RzOkRpZ2VzdFZhbHVlPgo8L2RzOlJlZmVyZW5jZT4KPC9kczpTaWduZWRJbmZvPgo8ZHM6U2lnbmF0dXJlVmFsdWU+"
////		"ClFFbFo3UU1HakJmaU1EN3ZyTDNJM25oRmNKZkM3dU1MZjBUb1kwQlZyc0dEeSt3YlI1N040WkRrL3JvQzY0Wnd3d3pBaVRmMC9mczIKRHM3eHVsUTFtVlorYUhHaDZXMWxSNVREZXBzMml6RTg1czgwRFExSCt0bkpCMS9nK25VNnlkUGUxaXhHVm1UNkhxOWRiVkozN2tZNQplQ3FYR3N3TjY5cDdZS0VDVTcvbkR6WThHNkEwcU5qbnJXd0FEa2M1WEhLRFplbHl3c0tCOXNNVkRlV1BpWjJjQTEyMmpabUwrWGhLCnFHbUExN3FVNGFEbTZ4b0VxbVZHeHkybTI1bVhwOEhRNmdNV2d5TEFjRzNlMHFUYmVPOUNhbFRTVXEvazhPSmQyTXZwNXloYXpKb2MKV1JJaUoyVGlXS1JQaVNtNmI1MDdqUlFvaUlpTlpKeGRibERKNlE9PQo8L2RzOlNpZ25hdHVyZVZhbHVlPgo8L2RzOl"
////		"NpZ25hdHVyZT48c2FtbHA6U3RhdHVzPjxzYW1scDpTdGF0dXNDb2RlIFZhbHVlPSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6c3RhdHVzOlN1Y2Nlc3MiLz48L3NhbWxwOlN0YXR1cz48c2FtbDpBc3NlcnRpb24gSUQ9ImpkTk03SnozWnpiNmRwMVNwQnlkc2Y2OXZFSiIgSXNzdWVJbnN0YW50PSIyMDE3LTA4LTAzVDE5OjIyOjAyLjE4NVoiIFZlcnNpb249IjIuMCIgeG1sbnM6c2FtbD0idXJuOm9hc2lzOm5hbWVzOnRjOlNBTUw6Mi4wOmFzc2VydGlvbiI+PHNhbWw6SXNzdWVyPnBvcnRhbDpzdGFnZTpjd3Q6c2FtbDI8L3NhbWw6SXNzdWVyPjxzYW1sOlN1YmplY3Q+"
////		"PHNhbWw6TmFtZUlEIEZvcm1hdD0idXJuOm9hc2lzOm5hbWVzOnRjOlNBTUw6MS4xOm5hbWVpZC1mb3JtYXQ6dW5zcGVjaWZpZWQiPjg1Y2QyMzIwLWZhMDctNGRlOS05NjQzLWVlNDdlYzMyNGMyNzwvc2FtbDpOYW1lSUQ+"
////		"PHNhbWw6U3ViamVjdENvbmZpcm1hdGlvbiBNZXRob2Q9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjIuMDpjbTpiZWFyZXIiPjxzYW1sOlN1YmplY3RDb25maXJtYXRpb25EYXRhIFJlY2lwaWVudD0iaHR0cHM6Ly90ZXN0Lm15dHJhdmVsc2l0ZS5jYXJsc29ud2Fnb25saXQuY29tL2MvcG9ydGFsL3NhbWwvYWNzIiBOb3RPbk9yQWZ0ZXI9IjIwMTctMDgtMDNUMTk6Mjc6MDIuMTg1WiIgSW5SZXNwb25zZVRvPSJfOTgxZWVmMWNhZWE5NjExZjcyZDkwOTg5YmE0NzdkMjk1MmU5OWMzNCIvPjwvc2FtbDpTdWJqZWN0Q29uZmlybWF0aW9uPjwvc2FtbDpTdWJqZWN0PjxzYW1sOkNvbmRpdGlvbnMgTm90QmVmb3JlPSIyMDE3LTA4LTAzVDE5OjE3OjAyLjE4NVoiIE5vdE"
////		"9uT3JBZnRlcj0iMjAxNy0wOC0wM1QxOToyNzowMi4xODVaIj48c2FtbDpBdWRpZW5jZVJlc3RyaWN0aW9uPjxzYW1sOkF1ZGllbmNlPnRlc3RfbGlmZXJheV9zYW1sX3NlcnZpY2VfcHJvdmlkZXI8L3NhbWw6QXVkaWVuY2U+PC9zYW1sOkF1ZGllbmNlUmVzdHJpY3Rpb24+PC9zYW1sOkNvbmRpdGlvbnM+PHNhbWw6QXV0aG5TdGF0ZW1lbnQgU2Vzc2lvbkluZGV4PSJqZE5NN0p6M1p6YjZkcDFTcEJ5ZHNmNjl2RUoiIEF1dGhuSW5zdGFudD0iMjAxNy0wOC0wM1QxOToyMjowMi4xNzJaIj48c2FtbDpBdXRobkNvbnRleHQ+PHNhbWw6QXV0aG5Db250ZXh0Q2xhc3NSZWY+"
////		"dXJuOm9hc2lzOm5hbWVzOnRjOlNBTUw6Mi4wOmFjOmNsYXNzZXM6dW5zcGVjaWZpZWQ8L3NhbWw6QXV0aG5Db250ZXh0Q2xhc3NSZWY+PC9zYW1sOkF1dGhuQ29udGV4dD48L3NhbWw6QXV0aG5TdGF0ZW1lbnQ+PHNhbWw6QXR0cmlidXRlU3RhdGVtZW50PjxzYW1sOkF0dHJpYnV0ZSBOYW1lPSJsYXN0TmFtZSIgTmFtZUZvcm1hdD0idXJuOm9hc2lzOm5hbWVzOnRjOlNBTUw6Mi4wOmF0dHJuYW1lLWZvcm1hdDpiYXNpYyI+"
////		"PHNhbWw6QXR0cmlidXRlVmFsdWUgeHNpOnR5cGU9InhzOnN0cmluZyIgeG1sbnM6eHM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvWE1MU2NoZW1hIiB4bWxuczp4c2k9Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvWE1MU2NoZW1hLWluc3RhbmNlIj5XYXNoaW5ndG9uPC9zYW1sOkF0dHJpYnV0ZVZhbHVlPjwvc2FtbDpBdHRyaWJ1dGU+"
////		"PHNhbWw6QXR0cmlidXRlIE5hbWU9InJvbGUiIE5hbWVGb3JtYXQ9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjIuMDphdHRybmFtZS1mb3JtYXQ6YmFzaWMiPjxzYW1sOkF0dHJpYnV0ZVZhbHVlIHhzaTp0eXBlPSJ4czpzdHJpbmciIHhtbG5zOnhzPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtYSIgeG1sbnM6eHNpPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtYS1pbnN0YW5jZSI+dHJhdmVsZXI8L3NhbWw6QXR0cmlidXRlVmFsdWU+"
////		"PC9zYW1sOkF0dHJpYnV0ZT48c2FtbDpBdHRyaWJ1dGUgTmFtZT0iaW1ydEFjY2Vzc1Rva2VuIiBOYW1lRm9ybWF0PSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXR0cm5hbWUtZm9ybWF0OnVuc3BlY2lmaWVkIj48c2FtbDpBdHRyaWJ1dGVWYWx1ZSB4c2k6dHlwZT0ieHM6c3RyaW5nIiB4bWxuczp4cz0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEiIHhtbG5zOnhzaT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEtaW5zdGFuY2UiPkozQTF3R3M0N2V6aEFrbklYR09MYXdZV01hck1mZmFOV1RYdDVna2prVFpFd1JFMElMaEg2VGVlTDFnZ2hrTmFuSnZacHlIeE5xeXgxbzE0V01vdkJkdTFielFKRmoycHB0REV0VmxYelhDM0ZEYk"
////		"Rpa0p1QXJMZzwvc2FtbDpBdHRyaWJ1dGVWYWx1ZT48L3NhbWw6QXR0cmlidXRlPjxzYW1sOkF0dHJpYnV0ZSBOYW1lPSJsYW5ndWFnZSIgTmFtZUZvcm1hdD0idXJuOm9hc2lzOm5hbWVzOnRjOlNBTUw6Mi4wOmF0dHJuYW1lLWZvcm1hdDpiYXNpYyI+"
////		"PHNhbWw6QXR0cmlidXRlVmFsdWUgeHNpOnR5cGU9InhzOnN0cmluZyIgeG1sbnM6eHM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvWE1MU2NoZW1hIiB4bWxuczp4c2k9Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvWE1MU2NoZW1hLWluc3RhbmNlIj5lbl9DQTwvc2FtbDpBdHRyaWJ1dGVWYWx1ZT48L3NhbWw6QXR0cmlidXRlPjxzYW1sOkF0dHJpYnV0ZSBOYW1lPSJpc0FkbWluIiBOYW1lRm9ybWF0PSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXR0cm5hbWUtZm9ybWF0OmJhc2ljIj48c2FtbDpBdHRyaWJ1dGVWYWx1ZSB4c2k6dHlwZT0ieHM6c3RyaW5nIiB4bWxuczp4cz0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEiIHhtbG5zOnhzaT0iaH"
////		"R0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEtaW5zdGFuY2UiPmZhbHNlPC9zYW1sOkF0dHJpYnV0ZVZhbHVlPjwvc2FtbDpBdHRyaWJ1dGU+"
////		"PHNhbWw6QXR0cmlidXRlIE5hbWU9InVzZXJOYW1lIiBOYW1lRm9ybWF0PSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXR0cm5hbWUtZm9ybWF0OmJhc2ljIj48c2FtbDpBdHRyaWJ1dGVWYWx1ZSB4c2k6dHlwZT0ieHM6c3RyaW5nIiB4bWxuczp4cz0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEiIHhtbG5zOnhzaT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEtaW5zdGFuY2UiPmxvYWR0ZXN0LUZhbm55Lldhc2hpbmd0b24tWnVuZG9uZ3JlZW4tNzk5NC0xMDYzMjI2QG1haWx0ZXN0LndvcmxkbWF0ZS5jb208L3NhbWw6QXR0cmlidXRlVmFsdWU+"
////		"PC9zYW1sOkF0dHJpYnV0ZT48c2FtbDpBdHRyaWJ1dGUgTmFtZT0iZmlyc3ROYW1lIiBOYW1lRm9ybWF0PSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXR0cm5hbWUtZm9ybWF0OmJhc2ljIj48c2FtbDpBdHRyaWJ1dGVWYWx1ZSB4c2k6dHlwZT0ieHM6c3RyaW5nIiB4bWxuczp4cz0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEiIHhtbG5zOnhzaT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEtaW5zdGFuY2UiPkZhbm55PC9zYW1sOkF0dHJpYnV0ZVZhbHVlPjwvc2FtbDpBdHRyaWJ1dGU+"
////		"PHNhbWw6QXR0cmlidXRlIE5hbWU9Imp3dEFjY2Vzc1Rva2VuIiBOYW1lRm9ybWF0PSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXR0cm5hbWUtZm9ybWF0OnVuc3BlY2lmaWVkIj48c2FtbDpBdHRyaWJ1dGVWYWx1ZSB4c2k6dHlwZT0ieHM6c3RyaW5nIiB4bWxuczp4cz0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEiIHhtbG5zOnhzaT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEtaW5zdGFuY2UiPmV5SmhiR2NpT2lKU1V6VXhNaUlzSW10cFpDSTZJblJ2YTJWdVEyVnlkQ0o5LmV5SnpZMjl3WlNJNlcxMHNJbk4xWWtsa0lqb2lRVG81UmtZME5DSXNJbVpwY25OMFRtRnRaU0k2SWtaaGJtNTVJaXdpYkdGemRFNWhiV1VpT2lKWF"
////		"lYTm9hVzVuZEc5dUlpd2lhWE5CY25KaGJtZGxjaUk2SW1aaGJITmxJaXdpZEc5d1NXUWlPaUpCT2prM05ETkRJaXdpYVdRaU9pSTROV05rTWpNeU1DMW1ZVEEzTFRSa1pUa3RPVFkwTXkxbFpUUTNaV016TWpSak1qY2lMQ0pwYzBGa2JXbHVJam9pWm1Gc2MyVWlMQ0owY21GMlpXeGxja2RWU1VRaU9pSkJPalF3TkRBM1FVTTFJaXdpZEhKaGRtVnNaWEpVZVhCbFIxVkpSQ0k2SWtFNk5qZzRNamtpTENKbGVIQWlPakUxTURFNE56UTFNako5LkR5U2Rpa3lVQ18zUWVCWGwtNGNQWkctN0hnSjNCSGhqV1VBanRXdUR2VGJlTW1GMTl5MEZ5ekc5ekFQX2ZRNVhBa0xNRnNJZ05CWlRiSVJZanVVVl94QjNwUzE0ZGU4elpCYTVXNlRpNVRmSmdPYVpseGZ4dHREUVBtam1Xakxr"
////		"VkJxNk0wRHlkNWx5UHhnM2FOQ19Pem92empPT3dwUDBQQVpRejZBX0lxY1FldWtBLUE5ZDBvbTZPU0drd2FpYkk0NFo5UURFODhMQVRNNlJveFZ2cmk1QUYyMGRDSFRFN1gyM3lFemFnaUJQb2RINlVMdE9fc01UNEx2cVNiX2RScDlhZEMwdUNyLV9Ib1YweWlKRlFaalU3ZUdWQWVLZ05WWElyLWQ4cTlQRGdVamlyRWpBN1hsS1ItdEJKOVRHWVRycDQ4eUV2eV9ZSDdhWE9oZW9QUTwvc2FtbDpBdHRyaWJ1dGVWYWx1ZT48L3NhbWw6QXR0cmlidXRlPjxzYW1sOkF0dHJpYnV0ZSBOYW1lPSJlbWFpbEFkZHJlc3MiIE5hbWVGb3JtYXQ9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjIuMDphdHRybmFtZS1mb3JtYXQ6YmFzaWMiPjxzYW1sOkF0dHJpYnV0ZVZhbHVlIHhzaT"
////		"p0eXBlPSJ4czpzdHJpbmciIHhtbG5zOnhzPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtYSIgeG1sbnM6eHNpPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtYS1pbnN0YW5jZSI+"
////		"bG9hZHRlc3QtRmFubnkuV2FzaGluZ3Rvbi1adW5kb25ncmVlbi03OTk0LTEwNjMyMjZAbWFpbHRlc3Qud29ybGRtYXRlLmNvbTwvc2FtbDpBdHRyaWJ1dGVWYWx1ZT48L3NhbWw6QXR0cmlidXRlPjxzYW1sOkF0dHJpYnV0ZSBOYW1lPSJpc0FycmFuZ2VyIiBOYW1lRm9ybWF0PSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXR0cm5hbWUtZm9ybWF0OmJhc2ljIj48c2FtbDpBdHRyaWJ1dGVWYWx1ZSB4c2k6dHlwZT0ieHM6c3RyaW5nIiB4bWxuczp4cz0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEiIHhtbG5zOnhzaT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEtaW5zdGFuY2UiPmZhbHNlPC9zYW1sOkF0dHJpYnV0ZVZhbHVlPj"
////		"wvc2FtbDpBdHRyaWJ1dGU+PHNhbWw6QXR0cmlidXRlIE5hbWU9InN1Ykd1aWQiIE5hbWVGb3JtYXQ9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjIuMDphdHRybmFtZS1mb3JtYXQ6YmFzaWMiPjxzYW1sOkF0dHJpYnV0ZVZhbHVlIHhzaTp0eXBlPSJ4czpzdHJpbmciIHhtbG5zOnhzPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtYSIgeG1sbnM6eHNpPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtYS1pbnN0YW5jZSI+"
////		"QTo5RkY0NDwvc2FtbDpBdHRyaWJ1dGVWYWx1ZT48L3NhbWw6QXR0cmlidXRlPjxzYW1sOkF0dHJpYnV0ZSBOYW1lPSJ0b3BHdWlkIiBOYW1lRm9ybWF0PSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXR0cm5hbWUtZm9ybWF0OmJhc2ljIj48c2FtbDpBdHRyaWJ1dGVWYWx1ZSB4c2k6dHlwZT0ieHM6c3RyaW5nIiB4bWxuczp4cz0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEiIHhtbG5zOnhzaT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEtaW5zdGFuY2UiPkE6OTc0M0M8L3NhbWw6QXR0cmlidXRlVmFsdWU+"
////		"PC9zYW1sOkF0dHJpYnV0ZT48c2FtbDpBdHRyaWJ1dGUgTmFtZT0iaWQiIE5hbWVGb3JtYXQ9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjIuMDphdHRybmFtZS1mb3JtYXQ6YmFzaWMiPjxzYW1sOkF0dHJpYnV0ZVZhbHVlIHhzaTp0eXBlPSJ4czpzdHJpbmciIHhtbG5zOnhzPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtYSIgeG1sbnM6eHNpPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtYS1pbnN0YW5jZSI+ODVjZDIzMjAtZmEwNy00ZGU5LTk2NDMtZWU0N2VjMzI0YzI3PC9zYW1sOkF0dHJpYnV0ZVZhbHVlPjwvc2FtbDpBdHRyaWJ1dGU+"
////		"PHNhbWw6QXR0cmlidXRlIE5hbWU9ImN3dFRyYXZlbGVySWQiIE5hbWVGb3JtYXQ9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjIuMDphdHRybmFtZS1mb3JtYXQ6YmFzaWMiPjxzYW1sOkF0dHJpYnV0ZVZhbHVlIHhzaTp0eXBlPSJ4czpzdHJpbmciIHhtbG5zOnhzPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtYSIgeG1sbnM6eHNpPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtYS1pbnN0YW5jZSI+QTo0MDQwN0FDNTwvc2FtbDpBdHRyaWJ1dGVWYWx1ZT48L3NhbWw6QXR0cmlidXRlPjwvc2FtbDpBdHRyaWJ1dGVTdGF0ZW1lbnQ+PC9zYW1sOkFzc2VydGlvbj48L3NhbWxwOlJlc3BvbnNlPg==", ENDITEM, 
		LAST);

	lr_end_transaction("Portal_002_Login_&_HomePage",LR_AUTO);

	lr_think_time(2);

	lr_start_transaction("Portal_003_My_Trips");

	web_url("my-trips", 
		"URL=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen/my-trips?zx=uxiwr5e3oyc6", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	lr_end_transaction("Portal_003_My_Trips",LR_AUTO);

	lr_think_time(1);
	
	lr_start_transaction("Portal_004_View_Trip");

	web_custom_request("my-trips_2", 
		"URL=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen/my-trips?p_p_id=tripdetailportlet_WAR_cwtportalportlet&p_p_lifecycle=2&p_p_resource_id=downloadItinerary", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen/my-trips", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"locator\":\"LOAD237\",\"creationDate\":\"2011-05-03\",\"reservationSystem\":\"SABRE\"}", 
		LAST);

	lr_end_transaction("Portal_004_View_Trip",LR_AUTO);

	lr_think_time(1);
	
	lr_start_transaction("Portal_005_Logout");

	web_reg_save_param("SAMLRequest_SLO.saml2",
		"LB=input type=\"hidden\" name=\"SAMLRequest\" value=\"",
		"RB=\"/>",
		"NotFound=ERROR",
		"Search=All",
		LAST);
	
	web_url("logout", 
		"URL=https://test.mytravelsite.carlsonwagonlit.com/c/portal/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen/my-trips", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	web_reg_save_param("SAMLResponse_SLO.saml2",
		"LB=<input type=\"hidden\" name=\"SAMLResponse\" value=\"",
		"RB=\"/>",
		"NotFound=ERROR",
		"Search=All",
		LAST);
	
	web_submit_data("SLO.saml2", 
		"Action=https://test.mytravel.carlsonwagonlit.com/idp/SLO.saml2", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://test.mytravelsite.carlsonwagonlit.com/c/portal/logout", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=SAMLRequest", "Value={SAMLRequest_SLO.saml2}", ENDITEM,
//		"PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiPz4KPHNhbWwycDpMb2dvdXRSZXF1ZXN0IERlc3RpbmF0aW9uPSJodHRwczovL3Rlc3QubXl0cmF2ZWwuY2FybHNvbndhZ29ubGl0LmNvbS9pZHAvU0xPLnNhbWwyIiBJRD0iXzc3YzRmNmYwNjZlZDY4OTM5YjA3OGQ4NjI1MjI2ZTNkNjliMjg4NzEiIElzc3VlSW5zdGFudD0iMjAxNy0wOC0wM1QxOToyMzoxNS4wMThaIiBWZXJzaW9uPSIyLjAiIHhtbG5zOnNhbWwycD0idXJuOm9hc2lzOm5hbWVzOnRjOlNBTUw6Mi4wOnByb3RvY29sIj48c2FtbDI6SXNzdWVyIHhtbG5zOnNhbWwyPSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXNzZXJ0aW9uIj50ZXN0X2xpZmVyYXlfc2FtbF9zZXJ2aWNlX3"
//		"Byb3ZpZGVyPC9zYW1sMjpJc3N1ZXI+PGRzOlNpZ25hdHVyZSB4bWxuczpkcz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC8wOS94bWxkc2lnIyI+PGRzOlNpZ25lZEluZm8+PGRzOkNhbm9uaWNhbGl6YXRpb25NZXRob2QgQWxnb3JpdGhtPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzEwL3htbC1leGMtYzE0biMiLz48ZHM6U2lnbmF0dXJlTWV0aG9kIEFsZ29yaXRobT0iaHR0cDovL3d3dy53My5vcmcvMjAwMC8wOS94bWxkc2lnI3JzYS1zaGExIi8+PGRzOlJlZmVyZW5jZSBVUkk9IiNfNzdjNGY2ZjA2NmVkNjg5MzliMDc4ZDg2MjUyMjZlM2Q2OWIyODg3MSI+PGRzOlRyYW5zZm9ybXM+"
//		"PGRzOlRyYW5zZm9ybSBBbGdvcml0aG09Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvMDkveG1sZHNpZyNlbnZlbG9wZWQtc2lnbmF0dXJlIi8+PGRzOlRyYW5zZm9ybSBBbGdvcml0aG09Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvMTAveG1sLWV4Yy1jMTRuIyIvPjwvZHM6VHJhbnNmb3Jtcz48ZHM6RGlnZXN0TWV0aG9kIEFsZ29yaXRobT0iaHR0cDovL3d3dy53My5vcmcvMjAwMC8wOS94bWxkc2lnI3NoYTEiLz48ZHM6RGlnZXN0VmFsdWU+V2hnREliaHFPZER4TFFBc1hBYnhaelo1ZmJnPTwvZHM6RGlnZXN0VmFsdWU+PC9kczpSZWZlcmVuY2U+"
//		"PC9kczpTaWduZWRJbmZvPjxkczpTaWduYXR1cmVWYWx1ZT5DNTd3Q1pWMEVLYWZhTUEyK3dMSllaY1JoVE02eFlqOTNMNkhabzJqVk1LZXpKZ29VQTdUcUxvc2lyNWJFa243ejVpRElxQms4K0w2ZmhtakdSeHYvdDE0dzJHdG9uR3FjcUNRbUdMWnRLOVcycXJCbDF3dzN3ck5vNko2Y3ZZNkE1NUs0U0IrcGlldngxSVozNjVKcHRuc0lKUUhkSmNsZ0lDcWJ6K2EzVlRHM0pCSDVlbmFaS1k1TDV3cWxrdy9hRXlSL2QzMU13RStaZHRoY1NLZ2pscjN3dVhSbTY1MXQwdGh0cEJSZjMrVCtla2lRaWkwWUF0MHhJNnlGOXBGdlFaUW9iMTNwcG9zZjk5b2RibW0rd2l4RzZWb3AvZEdvd0lEZnhEZmIzQ0VQQWFjQW9RNGxlcFQzb0hLbExlQy9ieHVQRE41WXA1aU0vUi9qVEQvVG"
//		"c9PTwvZHM6U2lnbmF0dXJlVmFsdWU+PGRzOktleUluZm8+PGRzOlg1MDlEYXRhPjxkczpYNTA5Q2VydGlmaWNhdGU+"
//		"TUlJRExEQ0NBaFNnQXdJQkFnSUVXVkVIVWpBTkJna3Foa2lHOXcwQkFRVUZBREJZTVJBd0RnWURWUVFHRXdkVmJtdHViM2R1TVF3dwpDZ1lEVlFRSUV3TkRWMVF4RERBS0JnTlZCQWNUQTBOWFZERU1NQW9HQTFVRUNoTURRMWRVTVF3d0NnWURWUVFMRXdORFYxUXhEREFLCkJnTlZCQU1UQTBOWFZEQWVGdzB4TnpBMk1qWXhNekE0TXpSYUZ3MHhOekE1TWpReE16QTRNelJhTUZneEVEQU9CZ05WQkFZVEIxVnUKYTI1dmQyNHhEREFLQmdOVkJBZ1RBME5YVkRFTU1Bb0dBMVVFQnhNRFExZFVNUXd3Q2dZRFZRUUtFd05EVjFReEREQUtCZ05WQkFzVApBME5YVkRFTU1Bb0dBMVVFQXhNRFExZFVNSUlCSWpBTkJna3Foa2lHOXcwQkFRRUZBQU9DQVE4QU1JSUJDZ0tDQVFFQX"
//		"BZTXJ2dTB4CkRXODRGYUxQRnQ0S1o3WGxFV01yN2haTWk4aDVsT1ZEWU51Z0VmbzdqZCtzeVVlWEJCQ2Jvb0tnKzlHSDVHa3k2UUVkVlVpMVNhSDYKbXgraXpTNEFlS0grTzBPb3QxSDk0YlhBbTExSTEyYUZXSGRIdEF2UUVqQ080a0x2NXdlbExxSlViMm9iU0xkRWpZUnNoem1qOXppbgpyeDgzOExuWjZUNG14YmNIblNZc2JRcDREWFpoRUtsQVRoMzRhSHVkajAyOTdoajNnU3BFeDYvRDZlQ1VOdnlnVDZMZEJlUjFNRXZHCnZGVzRQazRidVlwejFLanoyMHh4SkE0UitPTjFZTXVtYlhSRlF4NGRoSVhoeTZnVUVwN0pxbE0yK25MVFRFbnFwOEVmWThHbzZoZjQKay9vNHhla2pNWUx4SDIzRzRhOGNNZ3paVGFleS9RSURBUUFCTUEwR0NTcUdTSWIzRFFFQkJRVUFBNElC"
//		"QVFCM0RDOVVad1dIalV3TgpTZDRPOEI4RFY4NS91Q0w1QytHcUhxa1pHYXhkK3JUdkNSdWRqT1FSTit6SkpGOXdod3BQNVlycVljTzVRdmVUTEFsK0NoSjlIK3J4CnpZbnQvNEhWd2pvb0ZZd1pLYkNKSXFrQU9Da1FkVmdOMVZ4ZlNZZnZkenh1N2MzekJWSng2VDJqaGNJbHRKS2tobzBvS3hKblBNdWUKdkorMDhDUFZEYi9uWXg1TzdQRDNNRVRSZHZNWFpTK3UxUUVkNTdhQkNxSnlJWUxCWGhidW90MThGTDdFQ0luWGltaDNkTEFRdlhVMwpSZENCR2I1OFEvOHNWZFRvc2hQWnIzVDBhbWtLMTlkbGtVOUdGR0RoKzk1Vzhxank0YUJaVmV4WlFENFgwMEd3NWNaMGMyZm5iazFGCjZXQ0NsalFEbDJrNDdsRmtEK3M3bDNySTwvZHM6WDUwOUNlcnRpZmljYXRlPjwvZHM6WD"
//		"UwOURhdGE+PC9kczpLZXlJbmZvPjwvZHM6U2lnbmF0dXJlPjxzYW1sMjpOYW1lSUQgRm9ybWF0PSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoxLjE6bmFtZWlkLWZvcm1hdDp1bnNwZWNpZmllZCIgeG1sbnM6c2FtbDI9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjIuMDphc3NlcnRpb24iPjg1Y2QyMzIwLWZhMDctNGRlOS05NjQzLWVlNDdlYzMyNGMyNzwvc2FtbDI6TmFtZUlEPjxzYW1sMnA6U2Vzc2lvbkluZGV4PmpkTk03SnozWnpiNmRwMVNwQnlkc2Y2OXZFSjwvc2FtbDJwOlNlc3Npb25JbmRleD48L3NhbWwycDpMb2dvdXRSZXF1ZXN0Pg==", ENDITEM, 
		LAST);

	web_submit_data("slo", 
		"Action=https://test.mytravelsite.carlsonwagonlit.com/c/portal/saml/slo", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://test.mytravel.carlsonwagonlit.com/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=SAMLResponse", "Value={SAMLResponse_SLO.saml2}", ENDITEM, 
//		"PHNhbWxwOkxvZ291dFJlc3BvbnNlIFZlcnNpb249IjIuMCIgSUQ9IkViS0hwWGVZTF9qa0tKN0k1TzBrYjdOTF92ciIgSXNzdWVJbnN0YW50PSIyMDE3LTA4LTAzVDE5OjIzOjE1LjQzN1oiIEluUmVzcG9uc2VUbz0iXzc3YzRmNmYwNjZlZDY4OTM5YjA3OGQ4NjI1MjI2ZTNkNjliMjg4NzEiIERlc3RpbmF0aW9uPSJodHRwczovL3Rlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20vYy9wb3J0YWwvc2FtbC9zbG8iIHhtbG5zOnNhbWxwPSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6cHJvdG9jb2wiPjxzYW1sOklzc3VlciB4bWxuczpzYW1sPSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXNzZXJ0aW9uIj5wb3J0YWw6c3RhZ2U6Y3d0On"
//		"NhbWwyPC9zYW1sOklzc3Vlcj48ZHM6U2lnbmF0dXJlIHhtbG5zOmRzPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwLzA5L3htbGRzaWcjIj4KPGRzOlNpZ25lZEluZm8+CjxkczpDYW5vbmljYWxpemF0aW9uTWV0aG9kIEFsZ29yaXRobT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS8xMC94bWwtZXhjLWMxNG4jIi8+CjxkczpTaWduYXR1cmVNZXRob2QgQWxnb3JpdGhtPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNyc2Etc2hhMjU2Ii8+CjxkczpSZWZlcmVuY2UgVVJJPSIjRWJLSHBYZVlMX2prS0o3STVPMGtiN05MX3ZyIj4KPGRzOlRyYW5zZm9ybXM+"
//		"CjxkczpUcmFuc2Zvcm0gQWxnb3JpdGhtPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwLzA5L3htbGRzaWcjZW52ZWxvcGVkLXNpZ25hdHVyZSIvPgo8ZHM6VHJhbnNmb3JtIEFsZ29yaXRobT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS8xMC94bWwtZXhjLWMxNG4jIi8+CjwvZHM6VHJhbnNmb3Jtcz4KPGRzOkRpZ2VzdE1ldGhvZCBBbGdvcml0aG09Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvMDQveG1sZW5jI3NoYTI1NiIvPgo8ZHM6RGlnZXN0VmFsdWU+QnNnYVFpREcxeWlaR1h5a3hZN3hQRmN0K0NObkt2dWVvWTA1OU5aSHBDRT08L2RzOkRpZ2VzdFZhbHVlPgo8L2RzOlJlZmVyZW5jZT4KPC9kczpTaWduZWRJbmZvPgo8ZHM6U2lnbmF0dXJlVmFsdWU+"
//		"Cmc5d1pHT0R0Znd5U3Bwb1lRdUVHakZrQyttMHZYOUF6aGtWMTBWU0hhZW5xRFlGYzBFYWdtWlFMVHBVdlJUNU1MVTQ5c3JCZ2V2bzQKbDNBNGpPaEE2RDVhWmNmOTN6R2s3RXJrTFEyVDVKb2lOdTBTcE0yRHdtVzRySk8zUm5Za09TUlBMbWhZcG5NWUJtbTdiQWxnT0JWTQptMFdMZk1ITlcwWWhBY0toSC9KM3NmeUEyc0VtWm5rcEpTMnV5QkppcEVOdTlDMzNKTFBuM0JDRDlreHRYTDZFQ2lTSlMvVUZzQ0FJCmlad2tVZHYyY2Yya3BNWTZtdHEyMzQxeDF0RHo5aW4ycnU2QkM0d0I1MXkzbmROM2V6WVp4WkFFZjJoMXkrWGtmdkVlb0NING5qSncKZHNzTmNGek9SVXBENVlIU1p2bVFnbWxIZmxKeE0yN3FkUHpzenc9PQo8L2RzOlNpZ25hdHVyZVZhbHVlPgo8L2RzOl"
//		"NpZ25hdHVyZT48c2FtbHA6U3RhdHVzPjxzYW1scDpTdGF0dXNDb2RlIFZhbHVlPSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6c3RhdHVzOlN1Y2Nlc3MiLz48L3NhbWxwOlN0YXR1cz48L3NhbWxwOkxvZ291dFJlc3BvbnNlPg==", ENDITEM, 
		LAST);

	web_reg_save_param("SAMLRequest_SSO.saml2_2",
		"LB=input type=\"hidden\" name=\"SAMLRequest\" value=\"",
		"RB=\"/>",
		"NotFound=ERROR",
		"Search=All",
		LAST);
		
	web_url("guest", 
		"URL=https://test.mytravelsite.carlsonwagonlit.com/group/guest", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://test.mytravelsite.carlsonwagonlit.com/c/portal/logout", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
//
//	web_reg_find("Fail=NotFound",
//		"Search=Body",
//		"Text=Your gateway to business travel",
//		LAST);
	
	web_submit_data("SSO.saml2_2", 
		"Action=https://test.mytravel.carlsonwagonlit.com/idp/SSO.saml2", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://test.mytravelsite.carlsonwagonlit.com/c/portal/login?redirect=%2Fgroup%2Fguest&refererPlid=30692&p_l_id=20146", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=RelayState", "Value=/group/guest", ENDITEM, 
		"Name=SAMLRequest", "Value={SAMLRequest_SSO.saml2_2}", ENDITEM,
//		"PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiPz4KPHNhbWwycDpBdXRoblJlcXVlc3QgQXNzZXJ0aW9uQ29uc3VtZXJTZXJ2aWNlVVJMPSJodHRwczovL3Rlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20vYy9wb3J0YWwvc2FtbC9hY3MiIERlc3RpbmF0aW9uPSJodHRwczovL3Rlc3QubXl0cmF2ZWwuY2FybHNvbndhZ29ubGl0LmNvbS9pZHAvU1NPLnNhbWwyIiBGb3JjZUF1dGhuPSJmYWxzZSIgSUQ9Il9mZjMzYzdlY2UyMmRmNDc3MDdkM2VkZmQ5ZDZjOTMwOWU4MDBjN2JlIiBJc1Bhc3NpdmU9ImZhbHNlIiBJc3N1ZUluc3RhbnQ9IjIwMTctMDgtMDNUMTk6MjM6MTUuNzA1WiIgUHJvdG9jb2xCaW5kaW5nPSJ1cm46b2FzaXM6bm"
//		"FtZXM6dGM6U0FNTDoyLjA6YmluZGluZ3M6SFRUUC1QT1NUIiBWZXJzaW9uPSIyLjAiIHhtbG5zOnNhbWwycD0idXJuOm9hc2lzOm5hbWVzOnRjOlNBTUw6Mi4wOnByb3RvY29sIj48c2FtbDI6SXNzdWVyIHhtbG5zOnNhbWwyPSJ1cm46b2FzaXM6bmFtZXM6dGM6U0FNTDoyLjA6YXNzZXJ0aW9uIj50ZXN0X2xpZmVyYXlfc2FtbF9zZXJ2aWNlX3Byb3ZpZGVyPC9zYW1sMjpJc3N1ZXI+PGRzOlNpZ25hdHVyZSB4bWxuczpkcz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC8wOS94bWxkc2lnIyI+PGRzOlNpZ25lZEluZm8+"
//		"PGRzOkNhbm9uaWNhbGl6YXRpb25NZXRob2QgQWxnb3JpdGhtPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzEwL3htbC1leGMtYzE0biMiLz48ZHM6U2lnbmF0dXJlTWV0aG9kIEFsZ29yaXRobT0iaHR0cDovL3d3dy53My5vcmcvMjAwMC8wOS94bWxkc2lnI3JzYS1zaGExIi8+PGRzOlJlZmVyZW5jZSBVUkk9IiNfZmYzM2M3ZWNlMjJkZjQ3NzA3ZDNlZGZkOWQ2YzkzMDllODAwYzdiZSI+PGRzOlRyYW5zZm9ybXM+PGRzOlRyYW5zZm9ybSBBbGdvcml0aG09Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvMDkveG1sZHNpZyNlbnZlbG9wZWQtc2lnbmF0dXJlIi8+"
//		"PGRzOlRyYW5zZm9ybSBBbGdvcml0aG09Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvMTAveG1sLWV4Yy1jMTRuIyIvPjwvZHM6VHJhbnNmb3Jtcz48ZHM6RGlnZXN0TWV0aG9kIEFsZ29yaXRobT0iaHR0cDovL3d3dy53My5vcmcvMjAwMC8wOS94bWxkc2lnI3NoYTEiLz48ZHM6RGlnZXN0VmFsdWU+QVdQVmNBLzcyZVovOEtJZ2tXUkdWRVRWOFhzPTwvZHM6RGlnZXN0VmFsdWU+PC9kczpSZWZlcmVuY2U+"
//		"PC9kczpTaWduZWRJbmZvPjxkczpTaWduYXR1cmVWYWx1ZT5DeG9YOGVWL3cvamlMS0pqZTMrdmIrVzhWQUlQUmtFOFhha0hjZ0h3U3llRkFuZlpOSUhCSmxQQWdQN3VBNXRnZHNxUG43S0czUGFLMGZpakFnZE5nRXViOGs4cHFqNFlzTEdYM0xiZndGeGxsR3RSVnhwWEM0RG5NN0lTQ3VQY1pjUzVmeWs1RzlpLzhMU01hOHdzVktwSUlrYzRPTlMwbi9Yeit4Z0ZNa08vajNGbDduNDI1bUxMUWlWYjBOblM0V3RKZlJWeEpFb0JSdmRsYks3RmxOaWtkNEpXWW9oVlBIcUExRmNCM2RzUXA4M2pkcW1jV3RobWJCck54TzBOd2NIQlA5OVFwSGFITVRsRlFvM25EeXJXektzSys0NmlNK3cySGN2U1Z4RVhwQThqODhHUXYzSDVKWmRHL0psOUZUclRob1J6VldaYml5MWFTYkRPb2"
//		"c9PTwvZHM6U2lnbmF0dXJlVmFsdWU+PGRzOktleUluZm8+PGRzOlg1MDlEYXRhPjxkczpYNTA5Q2VydGlmaWNhdGU+"
//		"TUlJRExEQ0NBaFNnQXdJQkFnSUVXVkVIVWpBTkJna3Foa2lHOXcwQkFRVUZBREJZTVJBd0RnWURWUVFHRXdkVmJtdHViM2R1TVF3dwpDZ1lEVlFRSUV3TkRWMVF4RERBS0JnTlZCQWNUQTBOWFZERU1NQW9HQTFVRUNoTURRMWRVTVF3d0NnWURWUVFMRXdORFYxUXhEREFLCkJnTlZCQU1UQTBOWFZEQWVGdzB4TnpBMk1qWXhNekE0TXpSYUZ3MHhOekE1TWpReE16QTRNelJhTUZneEVEQU9CZ05WQkFZVEIxVnUKYTI1dmQyNHhEREFLQmdOVkJBZ1RBME5YVkRFTU1Bb0dBMVVFQnhNRFExZFVNUXd3Q2dZRFZRUUtFd05EVjFReEREQUtCZ05WQkFzVApBME5YVkRFTU1Bb0dBMVVFQXhNRFExZFVNSUlCSWpBTkJna3Foa2lHOXcwQkFRRUZBQU9DQVE4QU1JSUJDZ0tDQVFFQX"
//		"BZTXJ2dTB4CkRXODRGYUxQRnQ0S1o3WGxFV01yN2haTWk4aDVsT1ZEWU51Z0VmbzdqZCtzeVVlWEJCQ2Jvb0tnKzlHSDVHa3k2UUVkVlVpMVNhSDYKbXgraXpTNEFlS0grTzBPb3QxSDk0YlhBbTExSTEyYUZXSGRIdEF2UUVqQ080a0x2NXdlbExxSlViMm9iU0xkRWpZUnNoem1qOXppbgpyeDgzOExuWjZUNG14YmNIblNZc2JRcDREWFpoRUtsQVRoMzRhSHVkajAyOTdoajNnU3BFeDYvRDZlQ1VOdnlnVDZMZEJlUjFNRXZHCnZGVzRQazRidVlwejFLanoyMHh4SkE0UitPTjFZTXVtYlhSRlF4NGRoSVhoeTZnVUVwN0pxbE0yK25MVFRFbnFwOEVmWThHbzZoZjQKay9vNHhla2pNWUx4SDIzRzRhOGNNZ3paVGFleS9RSURBUUFCTUEwR0NTcUdTSWIzRFFFQkJRVUFBNElC"
//		"QVFCM0RDOVVad1dIalV3TgpTZDRPOEI4RFY4NS91Q0w1QytHcUhxa1pHYXhkK3JUdkNSdWRqT1FSTit6SkpGOXdod3BQNVlycVljTzVRdmVUTEFsK0NoSjlIK3J4CnpZbnQvNEhWd2pvb0ZZd1pLYkNKSXFrQU9Da1FkVmdOMVZ4ZlNZZnZkenh1N2MzekJWSng2VDJqaGNJbHRKS2tobzBvS3hKblBNdWUKdkorMDhDUFZEYi9uWXg1TzdQRDNNRVRSZHZNWFpTK3UxUUVkNTdhQkNxSnlJWUxCWGhidW90MThGTDdFQ0luWGltaDNkTEFRdlhVMwpSZENCR2I1OFEvOHNWZFRvc2hQWnIzVDBhbWtLMTlkbGtVOUdGR0RoKzk1Vzhxank0YUJaVmV4WlFENFgwMEd3NWNaMGMyZm5iazFGCjZXQ0NsalFEbDJrNDdsRmtEK3M3bDNySTwvZHM6WDUwOUNlcnRpZmljYXRlPjwvZHM6WD"
//		"UwOURhdGE+PC9kczpLZXlJbmZvPjwvZHM6U2lnbmF0dXJlPjxzYW1sMnA6TmFtZUlEUG9saWN5IEFsbG93Q3JlYXRlPSJ0cnVlIiBGb3JtYXQ9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjEuMTpuYW1laWQtZm9ybWF0OnVuc3BlY2lmaWVkIiB4bWxuczpzYW1sMnA9InVybjpvYXNpczpuYW1lczp0YzpTQU1MOjIuMDpwcm90b2NvbCIvPjwvc2FtbDJwOkF1dGhuUmVxdWVzdD4=", ENDITEM, 
		EXTRARES, 
		LAST);

	web_url("lwx93sjz", 
		"URL=https://widget.intercom.io/widget/lwx93sjz", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=https://test.mytravel.carlsonwagonlit.com/idp/SSO.saml2", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("ping_2", 
		"Action=https://api-iam.intercom.io/messenger/web/ping", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://test.mytravel.carlsonwagonlit.com/idp/SSO.saml2", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=app_id", "Value=lwx93sjz", ENDITEM, 
		"Name=v", "Value=3", ENDITEM, 
		"Name=g", "Value=d0294981254ef58e1591a551d99f33a86c193883", ENDITEM, 
		"Name=s", "Value=273df56d-184a-4d69-be3e-2ff9df361567", ENDITEM, 
		"Name=i", "Value=", ENDITEM, 
		"Name=r", "Value=https://test.mytravelsite.carlsonwagonlit.com/c/portal/login?redirect=%2Fgroup%2Fguest&refererPlid=30692&p_l_id=20146", ENDITEM, 
		"Name=platform", "Value=web", ENDITEM, 
		"Name=Idempotency-Key", "Value=f01400c", ENDITEM, 
		"Name=user_data", "Value={\"anonymous_id\":\"51ab9c69-4e24-4259-a006-ab42e9b3c914\"}", ENDITEM, 
		"Name=referer", "Value=https://test.mytravel.carlsonwagonlit.com/idp/SSO.saml2", ENDITEM, 
		LAST);

	lr_end_transaction("Portal_005_Logout",LR_AUTO);
	


	return 0;
}