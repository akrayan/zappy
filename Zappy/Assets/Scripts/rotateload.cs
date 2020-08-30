using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rotateload : MonoBehaviour {
    void Update()
    {
        transform.Rotate(Vector3.left * Time.deltaTime * 4, Space.World);
        transform.Rotate(Vector3.down * Time.deltaTime * 4, Space.World);
    }
}
