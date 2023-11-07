!create cl:Client
!create aa:AuthenticatorAuthorizer
!create paa:ProxyAuthenticatorAuthorizer
!create raa:RemoteAuthenticatorAuthorizer
!create a1:AuthenticatorComponent
!create a2:AuthorizerComponent
!insert (cl, aa) into request1
!insert (paa, raa) into represents
!insert (raa, a1) into A1
!insert (raa, a2) into A2
!insert (cl, raa) into request2
!insert (cl, paa) into request3
!cl.request()