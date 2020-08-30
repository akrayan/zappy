using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rotatesun : MonoBehaviour {

    void Update()
    {
        transform.Rotate(Vector3.left * Time.deltaTime, Space.World);
        transform.Rotate(Vector3.down * Time.deltaTime, Space.World);
    }
}
