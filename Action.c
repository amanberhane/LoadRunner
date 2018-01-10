Action()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.1");
	web_cleanup_cookies();
	web_cache_cleanup();
	web_set_max_html_param_len("99999");
	
//	web_set_max_html_param_len("9999999");
//	web_add_cookie("JSESSIONID=1799059914EFAFAA797E989792478D6C; DOMAIN=test.mytravelsite.carlsonwagonlit.com");
 	web_add_cookie("COOKIE_SUPPORT=true; DOMAIN=test.mytravelsite.carlsonwagonlit.com");
//	web_add_cookie("NSC_UFTU-mjgfsbz-dmvtufs_mcwt=ffffffff09ddf20845525d5f4f58455e445a4a423660; DOMAIN=test.mytravelsite.carlsonwagonlit.com");

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

// web_add_cookie("mp_1bcf19b82e62fdddf0740e7f74091db5_mixpanel=%7B%22distinct_id%22%3A%20%2215da98bcbdf2aa-06ded709d0411b-7b55796d-140000-15da98bcbe027a%22%2C%22%24initial_referrer%22%3A%20%22https%3A%2F%2Ftest.mytravelsite.carlsonwagonlit.com%2Fc%2Fportal%2Flogin%3Fredirect%3D%252F%26refererPlid%3D30692%26p_l_id%3D20146%22%2C%22%24initial_referring_domain%22%3A%20%22test.mytravelsite.carlsonwagonlit.com%22%7D; DOMAIN=test.mytravel.carlsonwagonlit.com");
// web_add_cookie("mp_mixpanel__c=0; DOMAIN=test.mytravel.carlsonwagonlit.com");

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

//web_add_cookie("mp_mixpanel__c=5; DOMAIN=test.mytravel.carlsonwagonlit.com");
//web_add_cookie("intercom-id-lwx93sjz=51ab9c69-4e24-4259-a006-ab42e9b3c914; DOMAIN=test.mytravel.carlsonwagonlit.com");

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


//web_add_cookie("mp_1bcf19b82e62fdddf0740e7f74091db5_mixpanel=%7B%22distinct_id%22%3A%20%2215da98bcbdf2aa-06ded709d0411b-7b55796d-140000-15da98bcbe027a%22%2C%22%24initial_referrer%22%3A%20%22https%3A%2F%2Ftest.mytravelsite.carlsonwagonlit.com%2Fc%2Fportal%2Flogin%3Fredirect%3D%252F%26refererPlid%3D30692%26p_l_id%3D20146%22%2C%22%24initial_referring_domain%22%3A%20%22test.mytravelsite.carlsonwagonlit.com%22%7D; DOMAIN=test.mytravelsite.carlsonwagonlit.com");
//web_add_cookie("mp_mixpanel__c=5; DOMAIN=test.mytravelsite.carlsonwagonlit.com");
//web_add_cookie("intercom-id-lwx93sjz=51ab9c69-4e24-4259-a006-ab42e9b3c914; DOMAIN=test.mytravelsite.carlsonwagonlit.com");
//web_add_cookie("LFR_SESSION_STATE_9240062=1501788128102; DOMAIN=test.mytravelsite.carlsonwagonlit.com");

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
//		EXTRARES, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-metal-web-1.0.16/metal/src/coreNamed.js&/o/frontend-js-metal-web-1.0.16/metal/src/core.js&/o/frontend-js-metal-web-1.0.16/metal/src/array/array.js&/o/frontend-js-metal-web-1.0.16/metal/src/async/async.js&/o/frontend-js-metal-web-1.0.16/metal/src/disposable/Disposable.js&/o/frontend-js-metal-web-1.0.16/metal/src/object/object.js&/o/frontend-js-metal-web-1.0.16/metal/src/string/string.js&/o/"
////		"frontend-js-metal-web-1.0.16/metal/src/metal.js&/o/frontend-js-metal-web-1.0.16/metal-dom/src/domData.js&/o/frontend-js-metal-web-1.0.16/metal-events/src/EventHandle.js&/o/frontend-js-metal-web-1.0.16/metal-events/src/EventEmitter.js&/o/frontend-js-metal-web-1.0.16/metal-events/src/EventEmitterProxy.js&/o/frontend-js-metal-web-1.0.16/metal-events/src/EventHandler.js&/o/frontend-js-metal-web-1.0.16/metal-events/src/events.js&/o/frontend-js-metal-web-1.0.16/metal-dom/src/DomDelegatedEventHandle.js&/"
////		"o/frontend-js-metal-web-1.0.16/metal-dom/src/DomEventHandle.js&/o/frontend-js-metal-web-1.0.16/metal-dom/src/domNamed.js&/o/frontend-js-metal-web-1.0.16/metal-dom/src/dom.js&/o/frontend-js-metal-web-1.0.16/metal-dom/src/DomEventEmitterProxy.js&/o/frontend-js-metal-web-1.0.16/metal-dom/src/features.js&/o/frontend-js-metal-web-1.0.16/metal-dom/src/globalEval.js&/o/frontend-js-metal-web-1.0.16/metal-dom/src/globalEvalStyles.js&/o/frontend-js-metal-web-1.0.16/metal-dom/src/events.js&/o/"
////		"frontend-js-metal-web-1.0.16/metal-dom/src/all/dom.js&/o/frontend-js-metal-web-1.0.16/metal-promise/src/promise/Promise.js&/o/frontend-js-spa-web-1.0.28/senna/src/globals/globals.js&/o/frontend-js-metal-web-1.0.16/metal-uri/src/parseFromAnchor.js&/o/frontend-js-metal-web-1.0.16/metal-uri/src/parse.js&/o/frontend-js-metal-web-1.0.16/metal-structs/src/MultiMap.js&/o/frontend-js-metal-web-1.0.16/metal-structs/src/TreeNode.js&/o/frontend-js-metal-web-1.0.16/metal-structs/src/all/structs.js", "Referer"
////		"=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-metal-web-1.0.16/metal-uri/src/Uri.js&/o/frontend-js-metal-web-1.0.16/metal-ajax/src/Ajax.js&/o/frontend-js-spa-web-1.0.28/senna/src/errors/errors.js&/o/frontend-js-spa-web-1.0.28/senna/src/utils/utils.js&/o/frontend-js-spa-web-1.0.28/senna/src/cacheable/Cacheable.js&/o/frontend-js-spa-web-1.0.28/senna/src/screen/Screen.js&/o/frontend-js-metal-web-1.0.16/metal-useragent/src/UA.js&/o/"
////		"frontend-js-spa-web-1.0.28/senna/src/screen/RequestScreen.js&/o/frontend-js-spa-web-1.0.28/senna/src/surface/Surface.js&/o/frontend-js-spa-web-1.0.28/senna/src/screen/HtmlScreen.js&/o/frontend-js-spa-web-1.0.28/liferay/util/Utils.es.js&/o/frontend-js-spa-web-1.0.28/liferay/screen/EventScreen.es.js&/o/frontend-js-spa-web-1.0.28/liferay/screen/ActionURLScreen.es.js&/o/frontend-js-metal-web-1.0.16/metal-debounce/src/debounce.js&/o/frontend-js-metal-web-1.0.16/metal-path-parser/src/pathParser.js&/o/"
////		"frontend-js-spa-web-1.0.28/senna/src/route/Route.js&/o/frontend-js-spa-web-1.0.28/senna/src/app/App.js&/o/frontend-js-spa-web-1.0.28/liferay/surface/Surface.es.js&/o/frontend-js-spa-web-1.0.28/liferay/app/App.es.js&/o/frontend-js-spa-web-1.0.28/liferay/screen/RenderURLScreen.es.js&/o/frontend-js-spa-web-1.0.28/liferay/init.es.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/event-move/event-move-min.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/o/cwt-portal-theme/css/aui/lexicon/fonts/alloy-font-awesome/font/fontawesome-alloy.eot?", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		//"Url=/o/cwt-portal-theme/images/hero-blur.jpg", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/widget-base/assets/skins/sam/widget-base.css&/o/frontend-js-web/aui/widget-stack/assets/skins/sam/widget-stack.css&/o/frontend-js-web/aui/aui-tooltip-base/assets/skins/sam/aui-tooltip-base.css&/o/frontend-js-web/aui/aui-alert/assets/skins/sam/aui-alert.css", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=https://js.api.here.com/v3/3.0/mapsjs-service.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=https://js.api.here.com/v3/3.0/mapsjs-core.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=https://js.api.here.com/v3/3.0/mapsjs-ui.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=https://js.api.here.com/v3/3.0/mapsjs-mapevents.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=https://js.api.here.com/v3/3.0/mapsjs-ui.css", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/o/frontend-js-web/liferay/available_languages.jsp?browserId=ie&themeId=cwtportaltheme_WAR_cwtportaltheme&colorSchemeId=01&minifierType=js&languageId=en_CA&b=7010&t=1501678036071", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/escape/escape-min.js&/o/frontend-js-web/aui/base-core/base-core-min.js&/o/frontend-js-web/aui/base-observable/base-observable-min.js&/o/frontend-js-web/aui/widget-base-ie/widget-base-ie-min.js&/o/frontend-js-web/aui/widget-autohide/widget-autohide-min.js&/o/frontend-js-web/aui/aui-widget-cssclass/aui-widget-cssclass-min.js&/o/frontend-js-web/aui/aui-widget-toggle/aui-widget-toggle-min.js&/o/"
////		"frontend-js-web/aui/transition/transition-min.js&/o/frontend-js-web/aui/aui-widget-transition/aui-widget-transition-min.js&/o/frontend-js-web/aui/aui-widget-trigger/aui-widget-trigger-min.js&/o/frontend-js-web/aui/aui-widget-position-align-suggestion/aui-widget-position-align-suggestion-min.js&/o/frontend-js-web/aui/aui-tooltip-base/aui-tooltip-base-min.js&/o/frontend-js-web/aui/aui-tooltip-delegate/aui-tooltip-delegate-min.js&/o/frontend-js-web/liferay/language.js&/o/frontend-js-web/aui/timers/"
////		"timers-min.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/aui-alert/aui-alert-min.js&/o/frontend-js-web/liferay/node.js&/o/frontend-js-web/liferay/portlet_base.js&/o/frontend-js-web/liferay/alert.js&/o/frontend-js-web/liferay/notification.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
//		"Url=/delegate/service/getInitDataGlobal", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
//		"Url=https://api.mixpanel.com/decide/?verbose=1&version=1&lib=web&token=1bcf19b82e62fdddf0740e7f74091db5&ip=1&_=1501788127929", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
//		"Url=https://api.mixpanel.com/track/?data="
//		"eyJldmVudCI6ICJtcF9wYWdlX3ZpZXciLCJwcm9wZXJ0aWVzIjogeyIkb3MiOiAiV2luZG93cyIsIiRicm93c2VyIjogIkludGVybmV0IEV4cGxvcmVyIiwiJHJlZmVycmVyIjogImh0dHBzOi8vdGVzdC5teXRyYXZlbC5jYXJsc29ud2Fnb25saXQuY29tLyIsIiRyZWZlcnJpbmdfZG9tYWluIjogInRlc3QubXl0cmF2ZWwuY2FybHNvbndhZ29ubGl0LmNvbSIsIiRjdXJyZW50X3VybCI6ICJodHRwczovL3Rlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20vZ3JvdXAvenVuZG9uZ3JlZW4tc3ViLTc5OTQtenVuZG9uZ3JlZW4jLyIsIiRicm93c2VyX3ZlcnNpb24iOiAxMSwiJHNjcmVlbl9oZWlnaHQiOiAxMDI0LCIkc2NyZWVuX3dpZHRoIjogMTI4MC"
//		"wibXBfbGliIjogIndlYiIsIiRsaWJfdmVyc2lvbiI6ICIyLjEzLjAiLCJkaXN0aW5jdF9pZCI6ICIxNWRhOThiY2JkZjJhYS0wNmRlZDcwOWQwNDExYi03YjU1Nzk2ZC0xNDAwMDAtMTVkYTk4YmNiZTAyN2EiLCIkaW5pdGlhbF9yZWZlcnJlciI6ICJodHRwczovL3Rlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20vYy9wb3J0YWwvbG9naW4%2FcmVkaXJlY3Q9JTJGJnJlZmVyZXJQbGlkPTMwNjkyJnBfbF9pZD0yMDE0NiIsIiRpbml0aWFsX3JlZmVycmluZ19kb21haW4iOiAidGVzdC5teXRyYXZlbHNpdGUuY2FybHNvbndhZ29ubGl0LmNvbSIsIm1wX3BhZ2UiOiAiaHR0cHM6Ly90ZXN0Lm15dHJhdmVsc2l0ZS5jYXJsc29ud2Fnb25saXQuY29tL2"
//		"dyb3VwL3p1bmRvbmdyZWVuLXN1Yi03OTk0LXp1bmRvbmdyZWVuIy8iLCJtcF9yZWZlcnJlciI6ICJodHRwczovL3Rlc3QubXl0cmF2ZWwuY2FybHNvbndhZ29ubGl0LmNvbS8iLCJtcF9icm93c2VyIjogIkludGVybmV0IEV4cGxvcmVyIiwibXBfcGxhdGZvcm0iOiAiV2luZG93cyIsInRva2VuIjogIjFiY2YxOWI4MmU2MmZkZGRmMDc0MGU3Zjc0MDkxZGI1In19&ip=1&_=1501788127934", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/aui-datatable-highlight/assets/skins/sam/aui-datatable-highlight.css&/o/frontend-js-web/aui/datatable-scroll/assets/skins/sam/datatable-scroll.css&/o/frontend-js-web/aui/datatable-sort/assets/skins/sam/datatable-sort.css&/o/frontend-js-web/aui/aui-datatable-property-list/assets/skins/sam/aui-datatable-property-list.css&/o/frontend-js-web/aui/widget-modality/assets/skins/sam/widget-modality.css&/o/"
////		"frontend-js-web/aui/aui-image-viewer-base/assets/skins/sam/aui-image-viewer-base.css&/o/frontend-js-web/aui/aui-image-viewer-multiple/assets/skins/sam/aui-image-viewer-multiple.css&/o/frontend-js-web/aui/aui-image-viewer/assets/skins/sam/aui-image-viewer.css&/o/frontend-js-web/aui/aui-tree-view/assets/skins/sam/aui-tree-view.css", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/datatable-base/assets/skins/sam/datatable-base.css&/o/frontend-js-web/aui/cssgrids/cssgrids-min.css&/o/frontend-js-web/aui/calendar-base/assets/skins/sam/calendar-base.css&/o/frontend-js-web/aui/calendarnavigator/assets/skins/sam/calendarnavigator.css&/o/frontend-js-web/aui/calendar/assets/skins/sam/calendar.css&/o/frontend-js-web/aui/overlay/assets/skins/sam/overlay.css&/o/frontend-js-web/aui/"
////		"cssbutton/cssbutton-min.css&/o/frontend-js-web/aui/aui-button-core/assets/skins/sam/aui-button-core.css&/o/frontend-js-web/aui/aui-datatable-base-cell-editor/assets/skins/sam/aui-datatable-base-cell-editor.css&/o/frontend-js-web/aui/aui-datatable-base-options-cell-editor/assets/skins/sam/aui-datatable-base-options-cell-editor.css&/o/frontend-js-web/aui/aui-datatable-core/assets/skins/sam/aui-datatable-core.css&/o/frontend-js-web/aui/aui-datatable-selection/assets/skins/sam/"
////		"aui-datatable-selection.css", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		//"Url=/o/cwt-portal-theme/images/_/node_modules/cwt-hotel-booking-spa/src/assets/images/new.758759c2b6ae90b431a72d7f7665d3c7.png", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/o/cwt-portal-theme/fonts/custom/icons_HotelBooking-Regular.eot?", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/group/zundongreen-sub-{sub_no}-zundongreen?p_p_id=onlineitineraryportlet_WAR_cwtportalportlet&p_p_lifecycle=2&p_p_resource_id=getItinerary&_onlineitineraryportlet_WAR_cwtportalportlet_dateNowString={Date}&behavior%5Bconnection%5D%5BcalculateBy%5D=false", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/model/model-min.js&/o/frontend-js-web/aui/model-list/model-list-min.js&/o/frontend-js-web/aui/datatable-core/datatable-core-min.js&/o/frontend-js-web/aui/view/view-min.js&/o/frontend-js-web/aui/datatable-head/datatable-head-min.js&/o/frontend-js-web/aui/datatable-body/datatable-body-min.js&/o/frontend-js-web/aui/datatable-table/datatable-table-min.js&/o/frontend-js-web/aui/datatable-base/"
////		"datatable-base-min.js&/o/frontend-js-web/aui/calendar-base/lang/calendar-base_en.js&/o/frontend-js-web/aui/datatype-date-parse/datatype-date-parse-min.js&/o/frontend-js-web/aui/datatype-date-format/lang/datatype-date-format_en-CA.js&/o/frontend-js-web/aui/datatype-date-format/datatype-date-format-min.js&/o/frontend-js-web/aui/datatype-date-math/datatype-date-math-min.js&/o/frontend-js-web/aui/calendar-base/calendar-base-min.js&/o/frontend-js-web/aui/calendarnavigator/calendarnavigator-min.js", "Re"
////		"ferer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/button-group/button-group-min.js&/o/frontend-js-web/aui/aui-button-core/aui-button-core-min.js&/o/frontend-js-web/aui/aui-toolbar/aui-toolbar-min.js&/o/frontend-js-web/aui/aui-datatable-base-cell-editor/aui-datatable-base-cell-editor-min.js&/o/frontend-js-web/aui/aui-datatable-base-options-cell-editor/aui-datatable-base-options-cell-editor-min.js&/o/frontend-js-web/aui/"
////		"aui-datatable-cell-editor-support/aui-datatable-cell-editor-support-min.js&/o/frontend-js-web/aui/aui-datatable-body/aui-datatable-body-min.js&/o/frontend-js-web/aui/aui-datatable-core/aui-datatable-core-min.js&/o/frontend-js-web/aui/aui-datatable-checkbox-cell-editor/aui-datatable-checkbox-cell-editor-min.js&/o/frontend-js-web/aui/aui-datatable-date-cell-editor/aui-datatable-date-cell-editor-min.js&/o/frontend-js-web/aui/aui-datatable-dropdown-cell-editor/aui-datatable-dropdown-cell-editor-min.js", 
////		"Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/aui-datatable-radio-cell-editor/aui-datatable-radio-cell-editor-min.js&/o/frontend-js-web/aui/aui-datatable-text-cell-editor/aui-datatable-text-cell-editor-min.js&/o/frontend-js-web/aui/aui-datatable-text-area-cell-editor/aui-datatable-text-area-cell-editor-min.js&/o/frontend-js-web/aui/aui-datatable-selection/aui-datatable-selection-min.js&/o/frontend-js-web/aui/aui-datatable-highlight/"
////		"aui-datatable-highlight-min.js&/o/frontend-js-web/aui/datatable-column-widths/datatable-column-widths-min.js&/o/frontend-js-web/aui/datatable-scroll/datatable-scroll-min.js&/o/frontend-js-web/aui/datatable-sort/lang/datatable-sort_en.js&/o/frontend-js-web/aui/datatable-sort/datatable-sort-min.js&/o/frontend-js-web/aui/aui-datatable-property-list/aui-datatable-property-list-min.js&/o/frontend-js-web/aui/widget-modality/widget-modality-min.js&/o/frontend-js-web/aui/color-base/color-base-min.js", "Re"
////		"ferer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/calendar/calendar-min.js&/o/frontend-js-web/aui/dd-ddm-base/dd-ddm-base-min.js&/o/frontend-js-web/aui/dd-drag/dd-drag-min.js&/o/frontend-js-web/aui/dd-ddm/dd-ddm-min.js&/o/frontend-js-web/aui/dd-ddm-drop/dd-ddm-drop-min.js&/o/frontend-js-web/aui/dd-drop/dd-drop-min.js&/o/frontend-js-web/aui/dd-drop-plugin/dd-drop-plugin-min.js&/o/frontend-js-web/aui/dd-delegate/dd-delegate-min.js&/o/"
////		"frontend-js-web/aui/dd-proxy/dd-proxy-min.js&/o/frontend-js-web/aui/sortable/sortable-min.js&/o/frontend-js-web/aui/datatype-number-parse/datatype-number-parse-min.js&/o/frontend-js-web/aui/datatype-number-format/datatype-number-format-min.js&/o/frontend-js-web/aui/aui-datatype-date-parse/aui-datatype-date-parse-min.js&/o/frontend-js-web/aui/aui-datatype/aui-datatype-min.js&/o/frontend-js-web/aui/button-core/button-core-min.js&/o/frontend-js-web/aui/button/button-min.js&/o/frontend-js-web/aui/"
////		"button-plugin/button-plugin-min.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/aui-sortable-list/aui-sortable-list-min.js&/o/frontend-js-web/liferay/item_selector_dialog.js&/o/frontend-js-web/aui/aui-tree-data/aui-tree-data-min.js&/o/frontend-js-web/aui/aui-tree-io/aui-tree-io-min.js&/o/frontend-js-web/aui/aui-tree-paginator/aui-tree-paginator-min.js&/o/frontend-js-web/aui/aui-tree-node/aui-tree-node-min.js&/o/frontend-js-web/aui/aui-tree-view/aui-tree-view-min.js&/o/"
////		"layout-taglib/layouts_tree/js/layouts_tree.js&/o/layout-taglib/layouts_tree/js/layouts_tree_node_radio.js&/o/layout-taglib/layouts_tree/js/layouts_tree_radio.js&/o/layout-taglib/layouts_tree/js/layouts_tree_node_task.js&/o/layout-taglib/layouts_tree/js/layouts_tree_selectable.js&/o/frontend-js-web/liferay/portlet_url.js&/o/frontend-js-web/liferay/translation_manager.js&/o/dynamic-data-mapping-web/js/ddm_form.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/"
////		"zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/anim-base/anim-base-min.js&/o/frontend-js-web/aui/anim-color/anim-color-min.js&/o/frontend-js-web/aui/anim-xy/anim-xy-min.js&/o/frontend-js-web/aui/anim-curve/anim-curve-min.js&/o/frontend-js-web/aui/anim-easing/anim-easing-min.js&/o/frontend-js-web/aui/anim-node-plugin/anim-node-plugin-min.js&/o/frontend-js-web/aui/anim-scroll/anim-scroll-min.js&/o/frontend-js-web/aui/aui-widget-responsive/"
////		"aui-widget-responsive-min.js&/o/frontend-js-web/aui/imageloader/imageloader-min.js&/o/frontend-js-web/aui/aui-image-viewer-base/aui-image-viewer-base-min.js&/o/frontend-js-web/aui/aui-image-viewer-multiple/aui-image-viewer-multiple-min.js&/o/frontend-js-web/aui/aui-image-viewer-slideshow/aui-image-viewer-slideshow-min.js&/o/frontend-js-web/aui/aui-image-viewer/aui-image-viewer-min.js&/o/frontend-js-web/aui/aui-map/aui-map-min.js&/o/frontend-js-web/aui/aui-set/aui-set-min.js&/o/frontend-js-web/aui/"
////		"dd-scroll/dd-scroll-min.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		//"Url=https://cdn.worldmate.com/portal-hero-img/12421.jpg", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/o/cwt-portal-theme/fonts/custom/cwt-icons.eot?", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		//"Url=https://apistage.worldmate.com/public/flights/img/airlines/SU.png", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo/?browserId=ie&minifierType=&languageId=en_CA&b=7010&t=1501678036071&/o/frontend-js-web/aui/querystring-parse/querystring-parse-min.js&/o/frontend-js-web/aui/aui-url/aui-url-min.js", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		//"Url=/cwt-services-proxy/v1.0/searchClientAccounts?clientSubUnitGuid={ClientSubGUID}", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		//"Url=/cwt-services-proxy/v1.0/getReasonCodes", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
//		"Url=/delegate/service/analyticsData?dateNowString={Date}", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
//		"Url=https://api.mixpanel.com/decide/?verbose=1&version=2&lib=web&token=1bcf19b82e62fdddf0740e7f74091db5&distinct_id=ce6208ee-b221-49c1-9301-98477bbc5632&ip=1&_=1501788133650", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/o/cwt-portal-theme/css/aui.css?browserId=ie&themeId=cwtportaltheme_WAR_cwtportaltheme&minifierType=css&languageId=en_CA&b=7010&t=1501773083624&zx=if4ecq7h71cc", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/o/frontend-css-web/main.css?browserId=ie&themeId=cwtportaltheme_WAR_cwtportaltheme&minifierType=css&languageId=en_CA&b=7010&t=1501678035842&zx=hv9lzhf1scsp", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/combo?browserId=ie&minifierType=css&languageId=en_CA&b=7010&t=1501678043744&/o/product-navigation-simulation-theme-contributor/css/simulation_panel.css&/o/product-navigation-product-menu-dxp-theme-contributor/product_navigation_product_menu.css&/o/product-navigation-control-menu-dxp-theme-contributor/product_navigation_control_menu.css&zx=k77uzs64yov", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
////		"Url=/o/cwt-portal-theme/css/main.css?browserId=ie&themeId=cwtportaltheme_WAR_cwtportaltheme&minifierType=css&languageId=en_CA&b=7010&t=1501773083624&zx=tz6ourj70bf7", "Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", ENDITEM, 
		LAST);

	lr_end_transaction("Portal_002_Login_&_HomePage",LR_AUTO);

	lr_think_time(2);

	lr_start_transaction("Portal_003_My_Trips");

	
//web_add_cookie("mp_mixpanel__c=6; DOMAIN=test.mytravelsite.carlsonwagonlit.com");
//web_add_cookie("mp_1bcf19b82e62fdddf0740e7f74091db5_mixpanel="
//		"%7B%22distinct_id%22%3A%20%22ce6208ee-b221-49c1-9301-98477bbc5632%22%2C%22%24initial_referrer%22%3A%20%22https%3A%2F%2Ftest.mytravelsite.carlsonwagonlit.com%2Fc%2Fportal%2Flogin%3Fredirect%3D%252F%26refererPlid%3D30692%26p_l_id%3D20146%22%2C%22%24initial_referring_domain%22%3A%20%22test.mytravelsite.carlsonwagonlit.com%22%2C%22Sub%20Identifier%22%3A%20%2292e3bbc2-15b0-404b-98fc-658e8e398b06%22%2C%22Top%20Identifier%22%3A%20%22665f4028-c64c-4ee6-aae1-a434af1d478f%22%2C%22User%20Identifier%22%3A%20%"
//		"22ce6208ee-b221-49c1-9301-98477bbc5632%22%2C%22Home%20City%20Location%22%3A%20-1%2C%22Home%20Country%20Location%22%3A%20-1%2C%22Home%20State%20Location%22%3A%20-1%2C%22Platform%20Type%22%3A%20%22Portal%22%2C%22Webview%20Version%22%3A%20999%2C%22Push%20Type%22%3A%20%22No%20Push%20-%20Web%22%2C%22Production%20Version%22%3A%20true%2C%22Entrance%20Trigger%22%3A%20%22Web%22%2C%22Number%20of%20Upcoming%20Trips%22%3A%200%2C%22Upcoming%20Trips%20Destinations%22%3A%20%5B%5D%2C%22Is%20There%20a%20Next%20Tri"
//		"p%22%3A%20false%2C%22Days%20To%20Next%20Trip%22%3A%20-1%2C%22Flights%20In%20Next%20Trip%22%3A%20-1%2C%22Meetings%20In%20Next%20Trip%22%3A%20-1%2C%22Car%20Rentals%20In%20Next%20Trip%22%3A%20-1%2C%22Ground%20Transportation%20In%20Next%20Trip%22%3A%20-1%2C%22Hotels%20In%20Next%20Upcoming%20Trip%22%3A%20-1%2C%22Missing%20A%20Hotel%22%3A%20false%2C%22Missing%20Hotel%20Locations%22%3A%20%22%22%2C%22Number%20of%20Past%20Trips%22%3A%201%2C%22Days%20from%20Last%20Trip%22%3A%20207%2C%22Is%20There%20a%20Curr"
//		"ent%20Trip%22%3A%20false%2C%22Current%20Trip%20Start%20Date%22%3A%20-1%2C%22Current%20Trip%20End%20Date%22%3A%20-1%2C%22Current%20Trip%20Destination%22%3A%20-1%2C%22Flights%20In%20Current%20Trip%22%3A%20-1%2C%22Meetings%20In%20Current%20Trip%22%3A%20-1%2C%22Car%20Rentals%20In%20Current%20Trip%22%3A%20-1%2C%22Ground%20Transportation%20In%20Current%20Trip%22%3A%20-1%2C%22Hotels%20In%20Current%20Trip%22%3A%20-1%2C%22Booking%20Items%20In%20Current%20Trip%22%3A%20-1%7D; DOMAIN="
//		"test.mytravelsite.carlsonwagonlit.com");
//web_add_cookie("LFR_SESSION_STATE_9240062=1501788155090; DOMAIN=test.mytravelsite.carlsonwagonlit.com");
//web_add_cookie("mp_mixpanel__c=0; DOMAIN=test.mytravelsite.carlsonwagonlit.com");

	web_url("my-trips", 
		"URL=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen/my-trips?zx=uxiwr5e3oyc6", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://test.mytravelsite.carlsonwagonlit.com/group/zundongreen-sub-{sub_no}-zundongreen", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		EXTRARES, 
//		"Url=/o/cwt-portal-theme/css/aui/lexicon/fonts/glyphicons-halflings-regular.eot?", ENDITEM, 
//		"Url=/delegate/service/getInitDataGlobal", ENDITEM, 
//		//"Url=https://cdn.worldmate.com/portal-trip-destination/12421.jpg", ENDITEM, 
//		"Url=https://api.mixpanel.com/track/?data="
//		"eyJldmVudCI6ICJQb3J0YWwgTXkgVHJpcHMgU2NyZWVuIERpc3BsYXllZCIsInByb3BlcnRpZXMiOiB7IjAiOiAieyIsIjEiOiAiXCIiLCIyIjogIk4iLCIzIjogInUiLCI0IjogIm0iLCI1IjogImIiLCI2IjogImUiLCI3IjogInIiLCI4IjogIiAiLCI5IjogIm8iLCIxMCI6ICJmIiwiMTEiOiAiICIsIjEyIjogIlUiLCIxMyI6ICJwIiwiMTQiOiAiYyIsIjE1IjogIm8iLCIxNiI6ICJtIiwiMTciOiAiaSIsIjE4IjogIm4iLCIxOSI6ICJnIiwiMjAiOiAiICIsIjIxIjogIlQiLCIyMiI6ICJyIiwiMjMiOiAiaSIsIjI0IjogInAiLCIyNSI6ICJzIiwiMjYiOiAiXCIiLCIyNyI6ICI6IiwiMjgiOiAiMSIsIjI5IjogIiwiLCIzMCI6ICJcIiIsIjMxIjogIlUiLCIzMi"
//		"I6ICJwIiwiMzMiOiAiYyIsIjM0IjogIm8iLCIzNSI6ICJtIiwiMzYiOiAiaSIsIjM3IjogIm4iLCIzOCI6ICJnIiwiMzkiOiAiICIsIjQwIjogIlQiLCI0MSI6ICJyIiwiNDIiOiAiaSIsIjQzIjogInAiLCI0NCI6ICJzIiwiNDUiOiAiICIsIjQ2IjogIk4iLCI0NyI6ICJhIiwiNDgiOiAibSIsIjQ5IjogImUiLCI1MCI6ICJzIiwiNTEiOiAiXCIiLCI1MiI6ICI6IiwiNTMiOiAiWyIsIjU0IjogIlwiIiwiNTUiOiAiVCIsIjU2IjogInIiLCI1NyI6ICJpIiwiNTgiOiAicCIsIjU5IjogIiAiLCI2MCI6ICJ0IiwiNjEiOiAibyIsIjYyIjogIiAiLCI2MyI6ICJEIiwiNjQiOiAiZSIsIjY1IjogIm4iLCI2NiI6ICJ2IiwiNjciOiAiZSIsIjY4IjogInIiLCI2OSI6ICIs"
//		"IiwiNzAiOiAiICIsIjcxIjogIkMiLCI3MiI6ICJPIiwiNzMiOiAiXCIiLCI3NCI6ICJdIiwiNzUiOiAiLCIsIjc2IjogIlwiIiwiNzciOiAiVSIsIjc4IjogInAiLCI3OSI6ICJjIiwiODAiOiAibyIsIjgxIjogIm0iLCI4MiI6ICJpIiwiODMiOiAibiIsIjg0IjogImciLCI4NSI6ICIgIiwiODYiOiAiVCIsIjg3IjogInIiLCI4OCI6ICJpIiwiODkiOiAicCIsIjkwIjogInMiLCI5MSI6ICIgIiwiOTIiOiAiRCIsIjkzIjogImUiLCI5NCI6ICJzIiwiOTUiOiAidCIsIjk2IjogImkiLCI5NyI6ICJuIiwiOTgiOiAiYSIsIjk5IjogInQiLCIxMDAiOiAiaSIsIjEwMSI6ICJvIiwiMTAyIjogIm4iLCIxMDMiOiAicyIsIjEwNCI6ICJcIiIsIjEwNSI6ICI6IiwiMTA2Ij"
//		"ogIlsiLCIxMDciOiAiXCIiLCIxMDgiOiAiRCIsIjEwOSI6ICJlIiwiMTEwIjogIm4iLCIxMTEiOiAidiIsIjExMiI6ICJlIiwiMTEzIjogInIiLCIxMTQiOiAiXCIiLCIxMTUiOiAiXSIsIjExNiI6ICIsIiwiMTE3IjogIlwiIiwiMTE4IjogIk4iLCIxMTkiOiAidSIsIjEyMCI6ICJtIiwiMTIxIjogImIiLCIxMjIiOiAiZSIsIjEyMyI6ICJyIiwiMTI0IjogIiAiLCIxMjUiOiAibyIsIjEyNiI6ICJmIiwiMTI3IjogIiAiLCIxMjgiOiAiUCIsIjEyOSI6ICJhIiwiMTMwIjogInMiLCIxMzEiOiAidCIsIjEzMiI6ICIgIiwiMTMzIjogIlQiLCIxMzQiOiAiciIsIjEzNSI6ICJpIiwiMTM2IjogInAiLCIxMzciOiAicyIsIjEzOCI6ICJcIiIsIjEzOSI6ICI6IiwiMTQw"
//		"IjogIjAiLCIxNDEiOiAiLCIsIjE0MiI6ICJcIiIsIjE0MyI6ICJQIiwiMTQ0IjogImEiLCIxNDUiOiAicyIsIjE0NiI6ICJ0IiwiMTQ3IjogIiAiLCIxNDgiOiAiVCIsIjE0OSI6ICJyIiwiMTUwIjogImkiLCIxNTEiOiAicCIsIjE1MiI6ICJzIiwiMTUzIjogIiAiLCIxNTQiOiAiTiIsIjE1NSI6ICJhIiwiMTU2IjogIm0iLCIxNTciOiAiZSIsIjE1OCI6ICJzIiwiMTU5IjogIlwiIiwiMTYwIjogIjoiLCIxNjEiOiAiWyIsIjE2MiI6ICJdIiwiMTYzIjogIiwiLCIxNjQiOiAiXCIiLCIxNjUiOiAiUCIsIjE2NiI6ICJhIiwiMTY3IjogInMiLCIxNjgiOiAidCIsIjE2OSI6ICIgIiwiMTcwIjogIlQiLCIxNzEiOiAiciIsIjE3MiI6ICJpIiwiMTczIjogInAiLCIxNz"
//		"QiOiAicyIsIjE3NSI6ICIgIiwiMTc2IjogIkQiLCIxNzciOiAiZSIsIjE3OCI6ICJzIiwiMTc5IjogInQiLCIxODAiOiAiaSIsIjE4MSI6ICJuIiwiMTgyIjogImEiLCIxODMiOiAidCIsIjE4NCI6ICJpIiwiMTg1IjogIm8iLCIxODYiOiAibiIsIjE4NyI6ICJzIiwiMTg4IjogIlwiIiwiMTg5IjogIjoiLCIxOTAiOiAiWyIsIjE5MSI6ICJdIiwiMTkyIjogIn0iLCIkb3MiOiAiV2luZG93cyIsIiRicm93c2VyIjogIkludGVybmV0IEV4cGxvcmVyIiwiJGN1cnJlbnRfdXJsIjogImh0dHBzOi8vdGVzdC5teXRyYXZlbHNpdGUuY2FybHNvbndhZ29ubGl0LmNvbS9ncm91cC96dW5kb25ncmVlbi1zdWItNzk5NC16dW5kb25ncmVlbi9teS10cmlwcyIsIiRicm93c2Vy"
//		"X3ZlcnNpb24iOiAxMSwiJHNjcmVlbl9oZWlnaHQiOiAxMDI0LCIkc2NyZWVuX3dpZHRoIjogMTI4MCwibXBfbGliIjogIndlYiIsIiRsaWJfdmVyc2lvbiI6ICIyLjEzLjAiLCJkaXN0aW5jdF9pZCI6ICJjZTYyMDhlZS1iMjIxLTQ5YzEtOTMwMS05ODQ3N2JiYzU2MzIiLCIkaW5pdGlhbF9yZWZlcnJlciI6ICJodHRwczovL3Rlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20vYy9wb3J0YWwvbG9naW4%2FcmVkaXJlY3Q9JTJGJnJlZmVyZXJQbGlkPTMwNjkyJnBfbF9pZD0yMDE0NiIsIiRpbml0aWFsX3JlZmVycmluZ19kb21haW4iOiAidGVzdC5teXRyYXZlbHNpdGUuY2FybHNvbndhZ29ubGl0LmNvbSIsIlN1YiBJZGVudGlmaWVyIjogIjkyZTNi"
//		"YmMyLTE1YjAtNDA0Yi05OGZjLTY1OGU4ZTM5OGIwNiIsIlRvcCBJZGVudGlmaWVyIjogIjY2NWY0MDI4LWM2NGMtNGVlNi1hYWUxLWE0MzRhZjFkNDc4ZiIsIlVzZXIgSWRlbnRpZmllciI6ICJjZTYyMDhlZS1iMjIxLTQ5YzEtOTMwMS05ODQ3N2JiYzU2MzIiLCJIb21lIENpdHkgTG9jYXRpb24iOiAtMSwiSG9tZSBDb3VudHJ5IExvY2F0aW9uIjogLTEsIkhvbWUgU3RhdGUgTG9jYXRpb24iOiAtMSwiUGxhdGZvcm0gVHlwZSI6ICJQb3J0YWwiLCJXZWJ2aWV3IFZlcnNpb24iOiA5OTksIlB1c2ggVHlwZSI6ICJObyBQdXNoIC0gV2ViIiwiUHJvZHVjdGlvbiBWZXJzaW9uIjogdHJ1ZSwiRW50cmFuY2UgVHJpZ2dlciI6ICJXZWIiLCJOdW1iZXIgb2YgVXBjb21pbm"
//		"cgVHJpcHMiOiAwLCJVcGNvbWluZyBUcmlwcyBEZXN0aW5hdGlvbnMiOiBbXSwiSXMgVGhlcmUgYSBOZXh0IFRyaXAiOiBmYWxzZSwiRGF5cyBUbyBOZXh0IFRyaXAiOiAtMSwiRmxpZ2h0cyBJbiBOZXh0IFRyaXAiOiAtMSwiTWVldGluZ3MgSW4gTmV4dCBUcmlwIjogLTEsIkNhciBSZW50YWxzIEluIE5leHQgVHJpcCI6IC0xLCJHcm91bmQgVHJhbnNwb3J0YXRpb24gSW4gTmV4dCBUcmlwIjogLTEsIkhvdGVscyBJbiBOZXh0IFVwY29taW5nIFRyaXAiOiAtMSwiTWlzc2luZyBBIEhvdGVsIjogZmFsc2UsIk1pc3NpbmcgSG90ZWwgTG9jYXRpb25zIjogIiIsIk51bWJlciBvZiBQYXN0IFRyaXBzIjogMSwiRGF5cyBmcm9tIExhc3QgVHJpcCI6IDIwNywiSXMgVGhl"
//		"cmUgYSBDdXJyZW50IFRyaXAiOiBmYWxzZSwiQ3VycmVudCBUcmlwIFN0YXJ0IERhdGUiOiAtMSwiQ3VycmVudCBUcmlwIEVuZCBEYXRlIjogLTEsIkN1cnJlbnQgVHJpcCBEZXN0aW5hdGlvbiI6IC0xLCJGbGlnaHRzIEluIEN1cnJlbnQgVHJpcCI6IC0xLCJNZWV0aW5ncyBJbiBDdXJyZW50IFRyaXAiOiAtMSwiQ2FyIFJlbnRhbHMgSW4gQ3VycmVudCBUcmlwIjogLTEsIkdyb3VuZCBUcmFuc3BvcnRhdGlvbiBJbiBDdXJyZW50IFRyaXAiOiAtMSwiSG90ZWxzIEluIEN1cnJlbnQgVHJpcCI6IC0xLCJCb29raW5nIEl0ZW1zIEluIEN1cnJlbnQgVHJpcCI6IC0xLCIkX19jIjogNn19&ip=1&_=1501788155118", ENDITEM, 
//		"Url=my-trips?p_p_id=tripdetailportlet_WAR_cwtportalportlet&p_p_lifecycle=2&p_p_resource_id=getItinerary&_tripdetailportlet_WAR_cwtportalportlet_dateNowString={Date}&behavior%5Bconnection%5D%5BcalculateBy%5D=false", ENDITEM, 
//		"Url=my-trips?p_p_id=tripdetailportlet_WAR_cwtportalportlet&p_p_lifecycle=2&p_p_resource_id=getPastTrips&_tripdetailportlet_WAR_cwtportalportlet_dateNowString={Date}", ENDITEM, 
//		//"Url=https://cdn.worldmate.com/portal-hero-img/12421.jpg", ENDITEM, 
//		"Url=https://api.mixpanel.com/track/?data="
//		"eyJldmVudCI6ICJQb3J0YWwgTXkgVHJpcHMgU2NyZWVuIERpc3BsYXllZCIsInByb3BlcnRpZXMiOiB7IjAiOiAieyIsIjEiOiAiXCIiLCIyIjogIk4iLCIzIjogInUiLCI0IjogIm0iLCI1IjogImIiLCI2IjogImUiLCI3IjogInIiLCI4IjogIiAiLCI5IjogIm8iLCIxMCI6ICJmIiwiMTEiOiAiICIsIjEyIjogIlUiLCIxMyI6ICJwIiwiMTQiOiAiYyIsIjE1IjogIm8iLCIxNiI6ICJtIiwiMTciOiAiaSIsIjE4IjogIm4iLCIxOSI6ICJnIiwiMjAiOiAiICIsIjIxIjogIlQiLCIyMiI6ICJyIiwiMjMiOiAiaSIsIjI0IjogInAiLCIyNSI6ICJzIiwiMjYiOiAiXCIiLCIyNyI6ICI6IiwiMjgiOiAiMSIsIjI5IjogIiwiLCIzMCI6ICJcIiIsIjMxIjogIlUiLCIzMi"
//		"I6ICJwIiwiMzMiOiAiYyIsIjM0IjogIm8iLCIzNSI6ICJtIiwiMzYiOiAiaSIsIjM3IjogIm4iLCIzOCI6ICJnIiwiMzkiOiAiICIsIjQwIjogIlQiLCI0MSI6ICJyIiwiNDIiOiAiaSIsIjQzIjogInAiLCI0NCI6ICJzIiwiNDUiOiAiICIsIjQ2IjogIk4iLCI0NyI6ICJhIiwiNDgiOiAibSIsIjQ5IjogImUiLCI1MCI6ICJzIiwiNTEiOiAiXCIiLCI1MiI6ICI6IiwiNTMiOiAiWyIsIjU0IjogIlwiIiwiNTUiOiAiVCIsIjU2IjogInIiLCI1NyI6ICJpIiwiNTgiOiAicCIsIjU5IjogIiAiLCI2MCI6ICJ0IiwiNjEiOiAibyIsIjYyIjogIiAiLCI2MyI6ICJEIiwiNjQiOiAiZSIsIjY1IjogIm4iLCI2NiI6ICJ2IiwiNjciOiAiZSIsIjY4IjogInIiLCI2OSI6ICIs"
//		"IiwiNzAiOiAiICIsIjcxIjogIkMiLCI3MiI6ICJPIiwiNzMiOiAiXCIiLCI3NCI6ICJdIiwiNzUiOiAiLCIsIjc2IjogIlwiIiwiNzciOiAiVSIsIjc4IjogInAiLCI3OSI6ICJjIiwiODAiOiAibyIsIjgxIjogIm0iLCI4MiI6ICJpIiwiODMiOiAibiIsIjg0IjogImciLCI4NSI6ICIgIiwiODYiOiAiVCIsIjg3IjogInIiLCI4OCI6ICJpIiwiODkiOiAicCIsIjkwIjogInMiLCI5MSI6ICIgIiwiOTIiOiAiRCIsIjkzIjogImUiLCI5NCI6ICJzIiwiOTUiOiAidCIsIjk2IjogImkiLCI5NyI6ICJuIiwiOTgiOiAiYSIsIjk5IjogInQiLCIxMDAiOiAiaSIsIjEwMSI6ICJvIiwiMTAyIjogIm4iLCIxMDMiOiAicyIsIjEwNCI6ICJcIiIsIjEwNSI6ICI6IiwiMTA2Ij"
//		"ogIlsiLCIxMDciOiAiXCIiLCIxMDgiOiAiRCIsIjEwOSI6ICJlIiwiMTEwIjogIm4iLCIxMTEiOiAidiIsIjExMiI6ICJlIiwiMTEzIjogInIiLCIxMTQiOiAiXCIiLCIxMTUiOiAiXSIsIjExNiI6ICIsIiwiMTE3IjogIlwiIiwiMTE4IjogIk4iLCIxMTkiOiAidSIsIjEyMCI6ICJtIiwiMTIxIjogImIiLCIxMjIiOiAiZSIsIjEyMyI6ICJyIiwiMTI0IjogIiAiLCIxMjUiOiAibyIsIjEyNiI6ICJmIiwiMTI3IjogIiAiLCIxMjgiOiAiUCIsIjEyOSI6ICJhIiwiMTMwIjogInMiLCIxMzEiOiAidCIsIjEzMiI6ICIgIiwiMTMzIjogIlQiLCIxMzQiOiAiciIsIjEzNSI6ICJpIiwiMTM2IjogInAiLCIxMzciOiAicyIsIjEzOCI6ICJcIiIsIjEzOSI6ICI6IiwiMTQw"
//		"IjogIjEiLCIxNDEiOiAiLCIsIjE0MiI6ICJcIiIsIjE0MyI6ICJQIiwiMTQ0IjogImEiLCIxNDUiOiAicyIsIjE0NiI6ICJ0IiwiMTQ3IjogIiAiLCIxNDgiOiAiVCIsIjE0OSI6ICJyIiwiMTUwIjogImkiLCIxNTEiOiAicCIsIjE1MiI6ICJzIiwiMTUzIjogIiAiLCIxNTQiOiAiTiIsIjE1NSI6ICJhIiwiMTU2IjogIm0iLCIxNTciOiAiZSIsIjE1OCI6ICJzIiwiMTU5IjogIlwiIiwiMTYwIjogIjoiLCIxNjEiOiAiWyIsIjE2MiI6ICJcIiIsIjE2MyI6ICJUIiwiMTY0IjogInIiLCIxNjUiOiAiaSIsIjE2NiI6ICJwIiwiMTY3IjogIiAiLCIxNjgiOiAidCIsIjE2OSI6ICJvIiwiMTcwIjogIiAiLCIxNzEiOiAiUyIsIjE3MiI6ICJhIiwiMTczIjogIm4iLCIxNz"
//		"QiOiAiICIsIjE3NSI6ICJKIiwiMTc2IjogIm8iLCIxNzciOiAicyIsIjE3OCI6ICJlIiwiMTc5IjogIiwiLCIxODAiOiAiICIsIjE4MSI6ICJDIiwiMTgyIjogIkEiLCIxODMiOiAiXCIiLCIxODQiOiAiXSIsIjE4NSI6ICIsIiwiMTg2IjogIlwiIiwiMTg3IjogIlAiLCIxODgiOiAiYSIsIjE4OSI6ICJzIiwiMTkwIjogInQiLCIxOTEiOiAiICIsIjE5MiI6ICJUIiwiMTkzIjogInIiLCIxOTQiOiAiaSIsIjE5NSI6ICJwIiwiMTk2IjogInMiLCIxOTciOiAiICIsIjE5OCI6ICJEIiwiMTk5IjogImUiLCIyMDAiOiAicyIsIjIwMSI6ICJ0IiwiMjAyIjogImkiLCIyMDMiOiAibiIsIjIwNCI6ICJhIiwiMjA1IjogInQiLCIyMDYiOiAiaSIsIjIwNyI6ICJvIiwiMjA4"
//		"IjogIm4iLCIyMDkiOiAicyIsIjIxMCI6ICJcIiIsIjIxMSI6ICI6IiwiMjEyIjogIlsiLCIyMTMiOiAiXCIiLCIyMTQiOiAiUyIsIjIxNSI6ICJhIiwiMjE2IjogIm4iLCIyMTciOiAiICIsIjIxOCI6ICJKIiwiMjE5IjogIm8iLCIyMjAiOiAicyIsIjIyMSI6ICJlIiwiMjIyIjogIlwiIiwiMjIzIjogIl0iLCIyMjQiOiAifSIsIiRvcyI6ICJXaW5kb3dzIiwiJGJyb3dzZXIiOiAiSW50ZXJuZXQgRXhwbG9yZXIiLCIkY3VycmVudF91cmwiOiAiaHR0cHM6Ly90ZXN0Lm15dHJhdmVsc2l0ZS5jYXJsc29ud2Fnb25saXQuY29tL2dyb3VwL3p1bmRvbmdyZWVuLXN1Yi03OTk0LXp1bmRvbmdyZWVuL215LXRyaXBzIy8iLCIkYnJvd3Nlcl92ZXJzaW9uIjogMTEsIiRzY3"
//		"JlZW5faGVpZ2h0IjogMTAyNCwiJHNjcmVlbl93aWR0aCI6IDEyODAsIm1wX2xpYiI6ICJ3ZWIiLCIkbGliX3ZlcnNpb24iOiAiMi4xMy4wIiwiZGlzdGluY3RfaWQiOiAiY2U2MjA4ZWUtYjIyMS00OWMxLTkzMDEtOTg0NzdiYmM1NjMyIiwiJGluaXRpYWxfcmVmZXJyZXIiOiAiaHR0cHM6Ly90ZXN0Lm15dHJhdmVsc2l0ZS5jYXJsc29ud2Fnb25saXQuY29tL2MvcG9ydGFsL2xvZ2luP3JlZGlyZWN0PSUyRiZyZWZlcmVyUGxpZD0zMDY5MiZwX2xfaWQ9MjAxNDYiLCIkaW5pdGlhbF9yZWZlcnJpbmdfZG9tYWluIjogInRlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20iLCJTdWIgSWRlbnRpZmllciI6ICI5MmUzYmJjMi0xNWIwLTQwNGItOThmYy02"
//		"NThlOGUzOThiMDYiLCJUb3AgSWRlbnRpZmllciI6ICI2NjVmNDAyOC1jNjRjLTRlZTYtYWFlMS1hNDM0YWYxZDQ3OGYiLCJVc2VyIElkZW50aWZpZXIiOiAiY2U2MjA4ZWUtYjIyMS00OWMxLTkzMDEtOTg0NzdiYmM1NjMyIiwiSG9tZSBDaXR5IExvY2F0aW9uIjogLTEsIkhvbWUgQ291bnRyeSBMb2NhdGlvbiI6IC0xLCJIb21lIFN0YXRlIExvY2F0aW9uIjogLTEsIlBsYXRmb3JtIFR5cGUiOiAiUG9ydGFsIiwiV2VidmlldyBWZXJzaW9uIjogOTk5LCJQdXNoIFR5cGUiOiAiTm8gUHVzaCAtIFdlYiIsIlByb2R1Y3Rpb24gVmVyc2lvbiI6IHRydWUsIkVudHJhbmNlIFRyaWdnZXIiOiAiV2ViIiwiTnVtYmVyIG9mIFVwY29taW5nIFRyaXBzIjogMCwiVXBjb21pbm"
//		"cgVHJpcHMgRGVzdGluYXRpb25zIjogW10sIklzIFRoZXJlIGEgTmV4dCBUcmlwIjogZmFsc2UsIkRheXMgVG8gTmV4dCBUcmlwIjogLTEsIkZsaWdodHMgSW4gTmV4dCBUcmlwIjogLTEsIk1lZXRpbmdzIEluIE5leHQgVHJpcCI6IC0xLCJDYXIgUmVudGFscyBJbiBOZXh0IFRyaXAiOiAtMSwiR3JvdW5kIFRyYW5zcG9ydGF0aW9uIEluIE5leHQgVHJpcCI6IC0xLCJIb3RlbHMgSW4gTmV4dCBVcGNvbWluZyBUcmlwIjogLTEsIk1pc3NpbmcgQSBIb3RlbCI6IGZhbHNlLCJNaXNzaW5nIEhvdGVsIExvY2F0aW9ucyI6ICIiLCJOdW1iZXIgb2YgUGFzdCBUcmlwcyI6IDEsIkRheXMgZnJvbSBMYXN0IFRyaXAiOiAyMDcsIklzIFRoZXJlIGEgQ3VycmVudCBUcmlwIjog"
//		"ZmFsc2UsIkN1cnJlbnQgVHJpcCBTdGFydCBEYXRlIjogLTEsIkN1cnJlbnQgVHJpcCBFbmQgRGF0ZSI6IC0xLCJDdXJyZW50IFRyaXAgRGVzdGluYXRpb24iOiAtMSwiRmxpZ2h0cyBJbiBDdXJyZW50IFRyaXAiOiAtMSwiTWVldGluZ3MgSW4gQ3VycmVudCBUcmlwIjogLTEsIkNhciBSZW50YWxzIEluIEN1cnJlbnQgVHJpcCI6IC0xLCJHcm91bmQgVHJhbnNwb3J0YXRpb24gSW4gQ3VycmVudCBUcmlwIjogLTEsIkhvdGVscyBJbiBDdXJyZW50IFRyaXAiOiAtMSwiQm9va2luZyBJdGVtcyBJbiBDdXJyZW50IFRyaXAiOiAtMSwiJF9fYyI6IDB9fQ%3D%3D&ip=1&_=1501788156633", ENDITEM, 
//		"Url=https://api.mixpanel.com/track/?data="
//		"eyJldmVudCI6ICJQb3J0YWwgTXkgVHJpcHMgU2NyZWVuIFVwY29taW5nIFRyaXAgSXRlbSBDbGljayIsInByb3BlcnRpZXMiOiB7IiRvcyI6ICJXaW5kb3dzIiwiJGJyb3dzZXIiOiAiSW50ZXJuZXQgRXhwbG9yZXIiLCIkY3VycmVudF91cmwiOiAiaHR0cHM6Ly90ZXN0Lm15dHJhdmVsc2l0ZS5jYXJsc29ud2Fnb25saXQuY29tL2dyb3VwL3p1bmRvbmdyZWVuLXN1Yi03OTk0LXp1bmRvbmdyZWVuL215LXRyaXBzIy8iLCIkYnJvd3Nlcl92ZXJzaW9uIjogMTEsIiRzY3JlZW5faGVpZ2h0IjogMTAyNCwiJHNjcmVlbl93aWR0aCI6IDEyODAsIm1wX2xpYiI6ICJ3ZWIiLCIkbGliX3ZlcnNpb24iOiAiMi4xMy4wIiwiZGlzdGluY3RfaWQiOiAiY2U2MjA4ZWUtYjIyMS"
//		"00OWMxLTkzMDEtOTg0NzdiYmM1NjMyIiwiJGluaXRpYWxfcmVmZXJyZXIiOiAiaHR0cHM6Ly90ZXN0Lm15dHJhdmVsc2l0ZS5jYXJsc29ud2Fnb25saXQuY29tL2MvcG9ydGFsL2xvZ2luP3JlZGlyZWN0PSUyRiZyZWZlcmVyUGxpZD0zMDY5MiZwX2xfaWQ9MjAxNDYiLCIkaW5pdGlhbF9yZWZlcnJpbmdfZG9tYWluIjogInRlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20iLCJTdWIgSWRlbnRpZmllciI6ICI5MmUzYmJjMi0xNWIwLTQwNGItOThmYy02NThlOGUzOThiMDYiLCJUb3AgSWRlbnRpZmllciI6ICI2NjVmNDAyOC1jNjRjLTRlZTYtYWFlMS1hNDM0YWYxZDQ3OGYiLCJVc2VyIElkZW50aWZpZXIiOiAiY2U2MjA4ZWUtYjIyMS00OWMxLTkz"
//		"MDEtOTg0NzdiYmM1NjMyIiwiSG9tZSBDaXR5IExvY2F0aW9uIjogLTEsIkhvbWUgQ291bnRyeSBMb2NhdGlvbiI6IC0xLCJIb21lIFN0YXRlIExvY2F0aW9uIjogLTEsIlBsYXRmb3JtIFR5cGUiOiAiUG9ydGFsIiwiV2VidmlldyBWZXJzaW9uIjogOTk5LCJQdXNoIFR5cGUiOiAiTm8gUHVzaCAtIFdlYiIsIlByb2R1Y3Rpb24gVmVyc2lvbiI6IHRydWUsIkVudHJhbmNlIFRyaWdnZXIiOiAiV2ViIiwiTnVtYmVyIG9mIFVwY29taW5nIFRyaXBzIjogMCwiVXBjb21pbmcgVHJpcHMgRGVzdGluYXRpb25zIjogW10sIklzIFRoZXJlIGEgTmV4dCBUcmlwIjogZmFsc2UsIkRheXMgVG8gTmV4dCBUcmlwIjogLTEsIkZsaWdodHMgSW4gTmV4dCBUcmlwIjogLTEsIk1lZX"
//		"RpbmdzIEluIE5leHQgVHJpcCI6IC0xLCJDYXIgUmVudGFscyBJbiBOZXh0IFRyaXAiOiAtMSwiR3JvdW5kIFRyYW5zcG9ydGF0aW9uIEluIE5leHQgVHJpcCI6IC0xLCJIb3RlbHMgSW4gTmV4dCBVcGNvbWluZyBUcmlwIjogLTEsIk1pc3NpbmcgQSBIb3RlbCI6IGZhbHNlLCJNaXNzaW5nIEhvdGVsIExvY2F0aW9ucyI6ICIiLCJOdW1iZXIgb2YgUGFzdCBUcmlwcyI6IDEsIkRheXMgZnJvbSBMYXN0IFRyaXAiOiAyMDcsIklzIFRoZXJlIGEgQ3VycmVudCBUcmlwIjogZmFsc2UsIkN1cnJlbnQgVHJpcCBTdGFydCBEYXRlIjogLTEsIkN1cnJlbnQgVHJpcCBFbmQgRGF0ZSI6IC0xLCJDdXJyZW50IFRyaXAgRGVzdGluYXRpb24iOiAtMSwiRmxpZ2h0cyBJbiBDdXJy"
//		"ZW50IFRyaXAiOiAtMSwiTWVldGluZ3MgSW4gQ3VycmVudCBUcmlwIjogLTEsIkNhciBSZW50YWxzIEluIEN1cnJlbnQgVHJpcCI6IC0xLCJHcm91bmQgVHJhbnNwb3J0YXRpb24gSW4gQ3VycmVudCBUcmlwIjogLTEsIkhvdGVscyBJbiBDdXJyZW50IFRyaXAiOiAtMSwiQm9va2luZyBJdGVtcyBJbiBDdXJyZW50IFRyaXAiOiAtMSwiRGF5cyBGcm9tIFN0YXJ0IERhdGUiOiAzMDQsIlRyaXAgTmFtZSI6ICJUcmlwIHRvIERlbnZlciwgQ08iLCJNaXNzaW5nIEhvdGVsIEluIFRyaXAiOiB0cnVlLCJUcmlwIE9yZGVyIjogMSwidG9rZW4iOiAiMWJjZjE5YjgyZTYyZmRkZGYwNzQwZTdmNzQwOTFkYjUiLCIkX19jIjogMX19&ip=1&_=1501788173139", ENDITEM, 
//		//"Url=https://apistage.worldmate.com/public/flights/img/airlines/SU.png", ENDITEM, 
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

//	web_add_cookie("mp_mixpanel__c=2; DOMAIN=test.mytravelsite.carlsonwagonlit.com");

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
		//"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

//web_add_cookie("mp_mixpanel__c=2; DOMAIN=test.mytravel.carlsonwagonlit.com");
//
//web_add_cookie("mp_1bcf19b82e62fdddf0740e7f74091db5_mixpanel="
//		"%7B%22distinct_id%22%3A%20%22ce6208ee-b221-49c1-9301-98477bbc5632%22%2C%22%24initial_referrer%22%3A%20%22https%3A%2F%2Ftest.mytravelsite.carlsonwagonlit.com%2Fc%2Fportal%2Flogin%3Fredirect%3D%252F%26refererPlid%3D30692%26p_l_id%3D20146%22%2C%22%24initial_referring_domain%22%3A%20%22test.mytravelsite.carlsonwagonlit.com%22%2C%22Sub%20Identifier%22%3A%20%2292e3bbc2-15b0-404b-98fc-658e8e398b06%22%2C%22Top%20Identifier%22%3A%20%22665f4028-c64c-4ee6-aae1-a434af1d478f%22%2C%22User%20Identifier%22%3A%20%"
//		"22ce6208ee-b221-49c1-9301-98477bbc5632%22%2C%22Home%20City%20Location%22%3A%20-1%2C%22Home%20Country%20Location%22%3A%20-1%2C%22Home%20State%20Location%22%3A%20-1%2C%22Platform%20Type%22%3A%20%22Portal%22%2C%22Webview%20Version%22%3A%20999%2C%22Push%20Type%22%3A%20%22No%20Push%20-%20Web%22%2C%22Production%20Version%22%3A%20true%2C%22Entrance%20Trigger%22%3A%20%22Web%22%2C%22Number%20of%20Upcoming%20Trips%22%3A%200%2C%22Upcoming%20Trips%20Destinations%22%3A%20%5B%5D%2C%22Is%20There%20a%20Next%20Tri"
//		"p%22%3A%20false%2C%22Days%20To%20Next%20Trip%22%3A%20-1%2C%22Flights%20In%20Next%20Trip%22%3A%20-1%2C%22Meetings%20In%20Next%20Trip%22%3A%20-1%2C%22Car%20Rentals%20In%20Next%20Trip%22%3A%20-1%2C%22Ground%20Transportation%20In%20Next%20Trip%22%3A%20-1%2C%22Hotels%20In%20Next%20Upcoming%20Trip%22%3A%20-1%2C%22Missing%20A%20Hotel%22%3A%20false%2C%22Missing%20Hotel%20Locations%22%3A%20%22%22%2C%22Number%20of%20Past%20Trips%22%3A%201%2C%22Days%20from%20Last%20Trip%22%3A%20207%2C%22Is%20There%20a%20Curr"
//		"ent%20Trip%22%3A%20false%2C%22Current%20Trip%20Start%20Date%22%3A%20-1%2C%22Current%20Trip%20End%20Date%22%3A%20-1%2C%22Current%20Trip%20Destination%22%3A%20-1%2C%22Flights%20In%20Current%20Trip%22%3A%20-1%2C%22Meetings%20In%20Current%20Trip%22%3A%20-1%2C%22Car%20Rentals%20In%20Current%20Trip%22%3A%20-1%2C%22Ground%20Transportation%20In%20Current%20Trip%22%3A%20-1%2C%22Hotels%20In%20Current%20Trip%22%3A%20-1%2C%22Booking%20Items%20In%20Current%20Trip%22%3A%20-1%7D; DOMAIN="
//		"test.mytravel.carlsonwagonlit.com");

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
//		"Url=../assets/fonts/IDM_Icons-Regular.eot", ENDITEM, 
//		"Url=../assets/images/img-7-2x.jpg", ENDITEM, 
//		"Url=../assets/images/img-6-2x.jpg", ENDITEM, 
//		"Url=../assets/images/img-5-2x.jpg", ENDITEM, 
//		"Url=../assets/images/img-1-2x.jpg", ENDITEM, 
//		"Url=../assets/images/img-4-2x.jpg", ENDITEM, 
//		"Url=../assets/images/img-3-2x.jpg", ENDITEM, 
//		"Url=../assets/images/img-2-2x.jpg", ENDITEM, 
//		"Url=https://api.mixpanel.com/track/?data="
//		"eyJldmVudCI6ICJtcF9wYWdlX3ZpZXciLCJwcm9wZXJ0aWVzIjogeyIkb3MiOiAiV2luZG93cyIsIiRicm93c2VyIjogIkludGVybmV0IEV4cGxvcmVyIiwiJHJlZmVycmVyIjogImh0dHBzOi8vdGVzdC5teXRyYXZlbHNpdGUuY2FybHNvbndhZ29ubGl0LmNvbS9jL3BvcnRhbC9sb2dpbj9yZWRpcmVjdD0lMkZncm91cCUyRmd1ZXN0JnJlZmVyZXJQbGlkPTMwNjkyJnBfbF9pZD0yMDE0NiIsIiRyZWZlcnJpbmdfZG9tYWluIjogInRlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20iLCIkY3VycmVudF91cmwiOiAiaHR0cHM6Ly90ZXN0Lm15dHJhdmVsLmNhcmxzb253YWdvbmxpdC5jb20vaWRwL1NTTy5zYW1sMiIsIiRicm93c2VyX3ZlcnNpb24iOi"
//		"AxMSwiJHNjcmVlbl9oZWlnaHQiOiAxMDI0LCIkc2NyZWVuX3dpZHRoIjogMTI4MCwibXBfbGliIjogIndlYiIsIiRsaWJfdmVyc2lvbiI6ICIyLjEzLjAiLCJkaXN0aW5jdF9pZCI6ICJjZTYyMDhlZS1iMjIxLTQ5YzEtOTMwMS05ODQ3N2JiYzU2MzIiLCIkaW5pdGlhbF9yZWZlcnJlciI6ICJodHRwczovL3Rlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20vYy9wb3J0YWwvbG9naW4%2FcmVkaXJlY3Q9JTJGJnJlZmVyZXJQbGlkPTMwNjkyJnBfbF9pZD0yMDE0NiIsIiRpbml0aWFsX3JlZmVycmluZ19kb21haW4iOiAidGVzdC5teXRyYXZlbHNpdGUuY2FybHNvbndhZ29ubGl0LmNvbSIsIlN1YiBJZGVudGlmaWVyIjogIjkyZTNiYmMyLTE1YjAtND"
//		"A0Yi05OGZjLTY1OGU4ZTM5OGIwNiIsIlRvcCBJZGVudGlmaWVyIjogIjY2NWY0MDI4LWM2NGMtNGVlNi1hYWUxLWE0MzRhZjFkNDc4ZiIsIlVzZXIgSWRlbnRpZmllciI6ICJjZTYyMDhlZS1iMjIxLTQ5YzEtOTMwMS05ODQ3N2JiYzU2MzIiLCJIb21lIENpdHkgTG9jYXRpb24iOiAtMSwiSG9tZSBDb3VudHJ5IExvY2F0aW9uIjogLTEsIkhvbWUgU3RhdGUgTG9jYXRpb24iOiAtMSwiUGxhdGZvcm0gVHlwZSI6ICJQb3J0YWwiLCJXZWJ2aWV3IFZlcnNpb24iOiA5OTksIlB1c2ggVHlwZSI6ICJObyBQdXNoIC0gV2ViIiwiUHJvZHVjdGlvbiBWZXJzaW9uIjogdHJ1ZSwiRW50cmFuY2UgVHJpZ2dlciI6ICJXZWIiLCJOdW1iZXIgb2YgVXBjb21pbmcgVHJpcHMiOiAw"
//		"LCJVcGNvbWluZyBUcmlwcyBEZXN0aW5hdGlvbnMiOiBbXSwiSXMgVGhlcmUgYSBOZXh0IFRyaXAiOiBmYWxzZSwiRGF5cyBUbyBOZXh0IFRyaXAiOiAtMSwiRmxpZ2h0cyBJbiBOZXh0IFRyaXAiOiAtMSwiTWVldGluZ3MgSW4gTmV4dCBUcmlwIjogLTEsIkNhciBSZW50YWxzIEluIE5leHQgVHJpcCI6IC0xLCJHcm91bmQgVHJhbnNwb3J0YXRpb24gSW4gTmV4dCBUcmlwIjogLTEsIkhvdGVscyBJbiBOZXh0IFVwY29taW5nIFRyaXAiOiAtMSwiTWlzc2luZyBBIEhvdGVsIjogZmFsc2UsIk1pc3NpbmcgSG90ZWwgTG9jYXRpb25zIjogIiIsIk51bWJlciBvZiBQYXN0IFRyaXBzIjogMSwiRGF5cyBmcm9tIExhc3QgVHJpcCI6IDIwNywiSXMgVGhlcmUgYSBDdXJyZW"
//		"50IFRyaXAiOiBmYWxzZSwiQ3VycmVudCBUcmlwIFN0YXJ0IERhdGUiOiAtMSwiQ3VycmVudCBUcmlwIEVuZCBEYXRlIjogLTEsIkN1cnJlbnQgVHJpcCBEZXN0aW5hdGlvbiI6IC0xLCJGbGlnaHRzIEluIEN1cnJlbnQgVHJpcCI6IC0xLCJNZWV0aW5ncyBJbiBDdXJyZW50IFRyaXAiOiAtMSwiQ2FyIFJlbnRhbHMgSW4gQ3VycmVudCBUcmlwIjogLTEsIkdyb3VuZCBUcmFuc3BvcnRhdGlvbiBJbiBDdXJyZW50IFRyaXAiOiAtMSwiSG90ZWxzIEluIEN1cnJlbnQgVHJpcCI6IC0xLCJCb29raW5nIEl0ZW1zIEluIEN1cnJlbnQgVHJpcCI6IC0xLCJtcF9wYWdlIjogImh0dHBzOi8vdGVzdC5teXRyYXZlbC5jYXJsc29ud2Fnb25saXQuY29tL2lkcC9TU08uc2FtbDIi"
//		"LCJtcF9yZWZlcnJlciI6ICJodHRwczovL3Rlc3QubXl0cmF2ZWxzaXRlLmNhcmxzb253YWdvbmxpdC5jb20vYy9wb3J0YWwvbG9naW4%2FcmVkaXJlY3Q9JTJGZ3JvdXAlMkZndWVzdCZyZWZlcmVyUGxpZD0zMDY5MiZwX2xfaWQ9MjAxNDYiLCJtcF9icm93c2VyIjogIkludGVybmV0IEV4cGxvcmVyIiwibXBfcGxhdGZvcm0iOiAiV2luZG93cyIsInRva2VuIjogIjFiY2YxOWI4MmU2MmZkZGRmMDc0MGU3Zjc0MDkxZGI1In19&ip=1&_=1501788196043", ENDITEM, 
//		"Url=https://api.mixpanel.com/track/?data="
//		"eyJldmVudCI6ICJMb2dpbiBQYWdlIERpc3BsYXllZCIsInByb3BlcnRpZXMiOiB7IiRvcyI6ICJXaW5kb3dzIiwiJGJyb3dzZXIiOiAiSW50ZXJuZXQgRXhwbG9yZXIiLCIkcmVmZXJyZXIiOiAiaHR0cHM6Ly90ZXN0Lm15dHJhdmVsc2l0ZS5jYXJsc29ud2Fnb25saXQuY29tL2MvcG9ydGFsL2xvZ2luP3JlZGlyZWN0PSUyRmdyb3VwJTJGZ3Vlc3QmcmVmZXJlclBsaWQ9MzA2OTImcF9sX2lkPTIwMTQ2IiwiJHJlZmVycmluZ19kb21haW4iOiAidGVzdC5teXRyYXZlbHNpdGUuY2FybHNvbndhZ29ubGl0LmNvbSIsIiRjdXJyZW50X3VybCI6ICJodHRwczovL3Rlc3QubXl0cmF2ZWwuY2FybHNvbndhZ29ubGl0LmNvbS9pZHAvU1NPLnNhbWwyIiwiJGJyb3dzZXJfdm"
//		"Vyc2lvbiI6IDExLCIkc2NyZWVuX2hlaWdodCI6IDEwMjQsIiRzY3JlZW5fd2lkdGgiOiAxMjgwLCJtcF9saWIiOiAid2ViIiwiJGxpYl92ZXJzaW9uIjogIjIuMTMuMCIsImRpc3RpbmN0X2lkIjogImNlNjIwOGVlLWIyMjEtNDljMS05MzAxLTk4NDc3YmJjNTYzMiIsIiRpbml0aWFsX3JlZmVycmVyIjogImh0dHBzOi8vdGVzdC5teXRyYXZlbHNpdGUuY2FybHNvbndhZ29ubGl0LmNvbS9jL3BvcnRhbC9sb2dpbj9yZWRpcmVjdD0lMkYmcmVmZXJlclBsaWQ9MzA2OTImcF9sX2lkPTIwMTQ2IiwiJGluaXRpYWxfcmVmZXJyaW5nX2RvbWFpbiI6ICJ0ZXN0Lm15dHJhdmVsc2l0ZS5jYXJsc29ud2Fnb25saXQuY29tIiwiU3ViIElkZW50aWZpZXIiOiAiOTJlM2JiYzIt"
//		"MTViMC00MDRiLTk4ZmMtNjU4ZThlMzk4YjA2IiwiVG9wIElkZW50aWZpZXIiOiAiNjY1ZjQwMjgtYzY0Yy00ZWU2LWFhZTEtYTQzNGFmMWQ0NzhmIiwiVXNlciBJZGVudGlmaWVyIjogImNlNjIwOGVlLWIyMjEtNDljMS05MzAxLTk4NDc3YmJjNTYzMiIsIkhvbWUgQ2l0eSBMb2NhdGlvbiI6IC0xLCJIb21lIENvdW50cnkgTG9jYXRpb24iOiAtMSwiSG9tZSBTdGF0ZSBMb2NhdGlvbiI6IC0xLCJQbGF0Zm9ybSBUeXBlIjogIlBvcnRhbCIsIldlYnZpZXcgVmVyc2lvbiI6IDk5OSwiUHVzaCBUeXBlIjogIk5vIFB1c2ggLSBXZWIiLCJQcm9kdWN0aW9uIFZlcnNpb24iOiB0cnVlLCJFbnRyYW5jZSBUcmlnZ2VyIjogIldlYiIsIk51bWJlciBvZiBVcGNvbWluZyBUcm"
//		"lwcyI6IDAsIlVwY29taW5nIFRyaXBzIERlc3RpbmF0aW9ucyI6IFtdLCJJcyBUaGVyZSBhIE5leHQgVHJpcCI6IGZhbHNlLCJEYXlzIFRvIE5leHQgVHJpcCI6IC0xLCJGbGlnaHRzIEluIE5leHQgVHJpcCI6IC0xLCJNZWV0aW5ncyBJbiBOZXh0IFRyaXAiOiAtMSwiQ2FyIFJlbnRhbHMgSW4gTmV4dCBUcmlwIjogLTEsIkdyb3VuZCBUcmFuc3BvcnRhdGlvbiBJbiBOZXh0IFRyaXAiOiAtMSwiSG90ZWxzIEluIE5leHQgVXBjb21pbmcgVHJpcCI6IC0xLCJNaXNzaW5nIEEgSG90ZWwiOiBmYWxzZSwiTWlzc2luZyBIb3RlbCBMb2NhdGlvbnMiOiAiIiwiTnVtYmVyIG9mIFBhc3QgVHJpcHMiOiAxLCJEYXlzIGZyb20gTGFzdCBUcmlwIjogMjA3LCJJcyBUaGVyZSBh"
//		"IEN1cnJlbnQgVHJpcCI6IGZhbHNlLCJDdXJyZW50IFRyaXAgU3RhcnQgRGF0ZSI6IC0xLCJDdXJyZW50IFRyaXAgRW5kIERhdGUiOiAtMSwiQ3VycmVudCBUcmlwIERlc3RpbmF0aW9uIjogLTEsIkZsaWdodHMgSW4gQ3VycmVudCBUcmlwIjogLTEsIk1lZXRpbmdzIEluIEN1cnJlbnQgVHJpcCI6IC0xLCJDYXIgUmVudGFscyBJbiBDdXJyZW50IFRyaXAiOiAtMSwiR3JvdW5kIFRyYW5zcG9ydGF0aW9uIEluIEN1cnJlbnQgVHJpcCI6IC0xLCJIb3RlbHMgSW4gQ3VycmVudCBUcmlwIjogLTEsIkJvb2tpbmcgSXRlbXMgSW4gQ3VycmVudCBUcmlwIjogLTEsIk9yaWdpbiI6ICJOb25lIiwidG9rZW4iOiAiMWJjZjE5YjgyZTYyZmRkZGYwNzQwZTdmNzQwOTFkYjUiLC"
//		"IkX19jIjogMn19&ip=1&_=1501788196039", ENDITEM, 
//		"Url=https://js.intercomcdn.com/fonts/proximanova-semibold.46e3f047.woff", ENDITEM, 
//		"Url=https://js.intercomcdn.com/fonts/proximanova-regular.a7942249.woff", ENDITEM, 
//		"Url=https://js.intercomcdn.com/fonts/proximanova-regular-italic.053a1112.woff", ENDITEM, 
//		"Url=https://js.intercomcdn.com/fonts/proximanova-semibold-italic.660bf63e.woff", ENDITEM, 
//		"Url=https://api.mixpanel.com/decide/?verbose=1&version=1&lib=web&token=1bcf19b82e62fdddf0740e7f74091db5&ip=1&_=1501788196030", ENDITEM, 
//		"Url=https://nexus-websocket-a.intercom.io/client-test", ENDITEM, 
//		"Url=https://nexus-websocket-b.intercom.io/client-test", ENDITEM, 
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
	
//	lr_think_time(12);
	

	return 0;
}