<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Sponsorer-Dashborad</title>
</head>
<body>
<%if(session.getAttribute("cemail")!=null)
	{%>

<jsp:include page="sponsorerheader.jsp"></jsp:include>

<jsp:include page="projects.jsp"></jsp:include>

<jsp:include page="footer.jsp"></jsp:include>


<%}
else
{
response.sendRedirect("login.jsp");
}%>
	
</body>
</html>