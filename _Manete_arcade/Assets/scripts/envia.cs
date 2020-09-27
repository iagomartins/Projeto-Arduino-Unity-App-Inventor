using UnityEngine;
using System.Collections;
using System.IO.Ports;
using System.Threading;
using UnityEngine.SceneManagement;


public class envia : MonoBehaviour {


	public int port;
	string vel="20";
	public static SerialPort sp;
	

	void Start () {

        DontDestroyOnLoad(gameObject);

        for (int i = 0; i < 20; i++)
        {
            try
            {
                OpenConnection(i);
                break;
            }
            catch
            {
                print("Porta " + i.ToString() + "inválida!");
            }
            finally
            {
                print("Bluetooth Conectado.");
            }
        }
	}
	
	void Update () {
        UpdateBluetooth();
	}

	public void OpenConnection(int port)
	{
        try
        {
            sp = new SerialPort(@"\\.\COM" + port, 9600);
            sp.Open();
            sp.ReadTimeout = 1;
            print("Conectado!");
        }
        catch
        {
            print("Porta inválida.");
        }
	}
	
	void OnApplicationQuit() 
	{
		sp.Close();
	}

    public static void LoadGameOver()
    {
        SceneManager.LoadScene(2);
    }

	public static void UpdateBluetooth(){
        char reading = (char)sp.ReadChar();

        if(reading == 'g')
        {
            SceneManager.LoadScene(2);
        }

        if (reading == 'r')
        {
            SceneManager.LoadScene(1);
        }
    }
    
    public static void SendCheese()
    {
        sp.Write("c");
    }
}
