using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cheese : MonoBehaviour
{
    private void OnTriggerEnter(Collider player)
    {
        envia.SendCheese();
        Destroy(gameObject);
    }
}
