using UnityEngine;
using System.Collections;
using System.IO.Ports;

public class envia2 : MonoBehaviour {
		//Definiçao da variavel velocidade
		public static int velocidade;
	   
		void Start () {
		}


     		
		// Update is called once per frame
		void Update () 
		{

		if(envia.sp.IsOpen)
		{   
			try
			{
				Mover((char)envia.sp.ReadByte());

			}
			catch(System.Exception)
			{
			}
		}

		//Mover(envia.direcaolida);//Caso a porta COM responda positivamente estao executaremos o metodo Mover()
		}
		
	

		//Metodo Mover que sera chamado a cada clique no Push Button
		void Mover(char direcao)
		{
			//Para a Direita
		if (direcao == 'a') 
			{
			//print("direcao = e");	
			transform.Translate(Vector2.left * velocidade * Time.deltaTime, Space.World);
			}

			//Para a Esquerda
		if (direcao == 'b') 
			{
			//print("direcao = d");	
			transform.Translate(Vector2.right * velocidade * Time.deltaTime, Space.World);
			}

		if (direcao == 'c') 
		{
			//print("direcao = c");	
			transform.Translate(Vector2.up * velocidade * Time.deltaTime, Space.World);
		}

		if (direcao == 'd') 
		{
			//print("direcao = b");	
			transform.Translate(Vector2.down * velocidade * Time.deltaTime, Space.World);
		}

		}
	}
	// Use this for initialization
	

