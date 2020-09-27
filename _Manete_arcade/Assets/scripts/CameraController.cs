using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    public Transform player;
    [Range(0.01f, 1)] public float cameraSmooth = 0.01f;    


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void LateUpdate()
    {
        FollowTarget();
    }

    void FollowTarget()
    {
        Vector3 newPos = player.position;
        transform.position = Vector3.Slerp(transform.position, newPos, cameraSmooth);
    }
}
