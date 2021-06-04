package com.code;
/**
 * @author liubo
 */

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

import javax.imageio.ImageIO;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class CheckCodeServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	// ���session����KEY
	public static final String RANDOMCODEKEY = "RANDOMCODEKEY";
	private Random random = new Random();
	// �H�����ͪ��r��
	private String randString = "0123456789";

	private int width = 80;
	private int height = 26;
	private int stringNum = 3;

	/*
	 * ��o�r��
	 */
	private Font getFont() {
		return new Font("Fixedsys", Font.CENTER_BASELINE, 18);

	}

	/*
	 * ��o�C��
	 */
	private Color getRandColor(int fc, int bc) {
		if (fc > 255) {
			fc = 255;
		}
		if (bc < 255) {
			bc = 255;
		}
		int r = fc + random.nextInt(bc - fc - 16);
		int g = fc + random.nextInt(bc - fc - 14);
		int b = fc + random.nextInt(bc - fc - 18);

		return new Color(r, g, b);
	}

	public void getRandcode(HttpServletRequest request,
			HttpServletResponse response) {
		HttpSession session = request.getSession();
		// BufferedImage���O�㦳�w�İϪ�image���Aimage���O�Ω�y�z�Ϲ���T����
		BufferedImage image = new BufferedImage(width, height,
				BufferedImage.TYPE_INT_BGR);
		// ����image����graphics����A�Ӫ���i�H�b�Ϲ��W�i��U��ø�s�ާ@
		Graphics g = image.getGraphics();
		g.fillRect(0, 0, width, height);
		g.setFont(new Font("Times New Roman", Font.ROMAN_BASELINE, 18));
		g.setColor(getRandColor(110, 133));

		String randomString = "";
		for (int i = 0; i <= stringNum; i++) {
			randomString = drowString(g, randomString, i);
		}
		session.removeAttribute(RANDOMCODEKEY);
		session.setAttribute(RANDOMCODEKEY, randomString);
		g.dispose();
		try {
			// �N�O���餤���Ϥ��q�L�y�ʧΦ���X��Τ��
			ImageIO.write(image, "JPEG", response.getOutputStream());
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	/*
	 * ø�s�r��
	 */
	private String drowString(Graphics g, String randomString, int i) {
		g.setFont(getFont());
		g.setColor(new Color(random.nextInt(101), random.nextInt(111), random
				.nextInt(121)));
		String rand = String.valueOf(getRandomString(random.nextInt(randString
				.length())));
		randomString += rand;
		g.translate(random.nextInt(3), random.nextInt(3));
		g.drawString(rand, 13 * i, 16);
		return randomString;
	}

	/*
	 * ����H���r��
	 */
	public String getRandomString(int num) {
		return String.valueOf(randString.charAt(num));
	}

	@Override
	protected void service(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {

		// �]�m�����������A�i�D�y������X�����e���Ϥ�
		response.setContentType("image/jpeg");
		// �]�m�^���Y��T�A�i�D�y�������n�w�s�����e
		response.setHeader("Pragma", "No-cache");
		response.setHeader("Cache-Control", "no-cache");
		response.setDateHeader("Expire", 0);

		try {
			getRandcode(request, response);
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		service(req,resp);
	}
	
}
