using CnControls;
using UnityEngine;

namespace CustomJoystick
{
    public class move_android : MonoBehaviour
    {
        public GameObject camera;
        private Vector3[] directionalVectors = { Vector3.forward, Vector3.back, Vector3.right, Vector3.left };
        public float panSpeed = 4.0f;

        private Transform _mainCameraTransform;

        private void Update()
        {
            if (CnInputManager.GetAxis("Horizontal") > 0)
            {
                camera.transform.Translate(new Vector3(panSpeed * Time.deltaTime, 0, 0));
            }

            if (CnInputManager.GetAxis("Horizontal") < 0)
            {
                camera.transform.Translate(new Vector3(-(panSpeed * Time.deltaTime), 0, 0));
            }

            if (CnInputManager.GetAxis("Vertical") < 0)
            {
                camera.transform.Translate(new Vector3(0, 0, -(panSpeed * Time.deltaTime)));
            }

            if (CnInputManager.GetAxis("Vertical") > 0)
            {
                camera.transform.Translate(new Vector3(0, 0, panSpeed * Time.deltaTime));
            }
        }
        /*      private void Update()
              {
                  var movementVector = new Vector3(CnInputManager.GetAxis("Horizontal"), 0f, CnInputManager.GetAxis("Vertical"));
                  if (movementVector.sqrMagnitude < 0.00001f) return;

                  // Clamping
                  Vector3 closestDirectionVector = directionalVectors[0];
                  float closestDot = Vector3.Dot(movementVector, closestDirectionVector);
                  for (int i = 1; i < directionalVectors.Length; i++)
                  {
                      float dot = Vector3.Dot(movementVector, directionalVectors[i]);
                      if (dot < closestDot)
                      {
                          closestDirectionVector = directionalVectors[i];
                          closestDot = dot;
                      }
                  }

                  // closestDirectionVector is what we need
                  var transformedDirection = _mainCameraTransform.InverseTransformDirection(closestDirectionVector);
                  transformedDirection.y = 0f;
                  transformedDirection.Normalize();

                  transform.position += transformedDirection * Time.deltaTime;
              }*/
    }
}