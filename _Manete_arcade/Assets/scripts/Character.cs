using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))]
public class Character : MonoBehaviour
{
    public float speed;

    private Animator animController;
    private Rigidbody rig;
    private float hAxis;
    private float vAxis;
    private Vector3 movement;
    private bool running = false;

    // Start is called before the first frame update
    void Start()
    {
        rig = GetComponent<Rigidbody>();
        animController = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        hAxis = Input.GetAxis("Horizontal");
        vAxis = Input.GetAxis("Vertical");

        Mover();
    }

    void Mover()
    {
        movement = new Vector3(hAxis, 0, vAxis) * speed * Time.deltaTime;
        rig.MovePosition(transform.position + movement);
        if (hAxis != 0 || vAxis != 0 && !running)
        {
            running = true;
            animController.SetBool("run", true);
        }
        else if (hAxis == 0 || vAxis == 0 && running)
        {
            animController.SetBool("run", false);
            running = false;
        }
        //Debug.Log("Input: " + ((Input.GetAxis("Horizontal") + Input.GetAxis("Vertical")) / 2));
    }        


private void OnCollisionEnter(Collision collision)
    {
        if(collision.transform.tag == "Final")
        {
            //Chamar final de fase.
            Debug.Log("Colidiu com final!");
            envia.LoadGameOver();
        }
    }    
}
