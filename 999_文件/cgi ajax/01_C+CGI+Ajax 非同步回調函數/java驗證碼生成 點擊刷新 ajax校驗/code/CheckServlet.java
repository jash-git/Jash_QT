package com.code;
/**
 * @author liubo
 */
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class CheckServlet extends HttpServlet {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		this.doPost(request, response);
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		PrintWriter out = response.getWriter();
		String check = request.getParameter("code");
		try {
			String code = (String) request.getSession().getAttribute(
					"RANDOMCODEKEY");

			if (code.equals(check)) {
				out.write("OK");
			} else {
				out.write("NO");
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			out.close();
		}

	}

}
