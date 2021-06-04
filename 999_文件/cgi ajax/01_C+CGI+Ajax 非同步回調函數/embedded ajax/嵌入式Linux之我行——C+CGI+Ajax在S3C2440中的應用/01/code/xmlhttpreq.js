/*
 *創建非同步訪問物件
 */
function createXHR() 
{
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

/*
 *非同步訪問提交處理
 */
function sender() 
{
    xhr = createXHR();

    if(xhr)
    {
        xhr.onreadystatechange=callbackFunction;
    
        //test.cgi後面跟個cur_time參數是為了防止Ajax頁面緩存
        xhr.open("GET", "test.cgi?cur_time=" + newDate().getTime());
    
        xhr.send(null);
    }
    else
    {
        //XMLHttpRequest對象創建失敗
        alert("流覽器不支持，請更換流覽器！");
    }
}

/*
 *非同步回調函數處理
 */
function callbackFunction()
{
    if (xhr.readyState == 4) 
    {
        if (xhr.status == 200) 
        {
            var returnValue = xhr.responseText;

            if(returnValue != null && returnValue.length > 0)
            {
                document.getElementById("current_time").innerHTML =returnValue;
            }
            else
            {
                alert("結果為空！");
            }
        } 
        else 
        {
            alert("頁面出現異常！");
        }
    }
}

