function createXHR() 
{
	/*�ЫثD�P�B�X�ݪ���*/
	var xhr;
	try 
	{
		xhr = new ActiveXObject("Msxml2.XMLHTTP");
	} 
	catch (e) 
	{
		try 
		{
			xhr = new ActiveXObject("Microsoft.XMLHTTP");
		}
		catch(E) 
		{
			xhr = false;
		}
	}

	if (!xhr && typeof XMLHttpRequest != 'undefined') 
	{
		xhr = new XMLHttpRequest();
	}

	return xhr;
}

function sender() 
{
	/*�D�P�B�X�ݴ���B�z*/
	xhr = createXHR();

	if(xhr)
	{
		xhr.onreadystatechange=callbackFunction;
        //test.cgi�᭱���cur_time�ѼƬO���F����Ajax�����w�s
		xhr.open("GET", "test.cgi?cur_time=" + new Date().getTime());

		xhr.send(null);
	}
	else
	{
		//XMLHttpRequest��H�Ыإ���
		alert("�y����������A�Ч󴫬y�� ���I");
	}
}

function callbackFunction()
{
	/*�D�P�B�^�ը�ƳB�z*/
	if (xhr.readyState == 4) 
	{
		if (xhr.status == 200) 
		{
			var returnValue = xhr.responseText;
			if(returnValue != null && returnValue.length > 0)
			{
				document.getElementById("current_time").innerHTML = returnValue;
			}
			else
			{
				alert("���G���šI");
			}
		} 
		else 
		{
			alert("�����X�{���`�I");
		}
	}
}
