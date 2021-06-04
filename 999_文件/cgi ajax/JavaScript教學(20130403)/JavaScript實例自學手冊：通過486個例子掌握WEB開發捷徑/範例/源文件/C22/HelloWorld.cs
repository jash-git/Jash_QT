using System;
using System.Web;
using System.Collections;
using System.Web.Services;
using System.Web.Services.Protocols;


/// <summary>
/// 返回HelloWorld 
/// </summary>
[WebService(Namespace = "http://tempuri.org/")]
[WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
public class HelloWorld : System.Web.Services.WebService 
{
    [WebMethod]
    public int Hello_World(int x,int y) {
        return x * y;
    }
}